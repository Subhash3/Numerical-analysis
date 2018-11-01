/*
This program finds the roots of any equation by using bisection method. In this method an interval [a, b] is taken initially and checks if f(x) has any roots or not. If f(a)*f(b)< 0 then f(x) has atleast one root. Then the intervel is bisected at a point m = (a+b)/2 and if f(a)*f(m) < 0, then the interval is updated as [a, m], else the inverval is updated as [m, b], and the process goes on.....

Finally we find m such that m = a/2 = b/2. That is the point of convergence of 
f(x).
 
Input: -Limits of the initial interval i.e a, b.
       -Any function F(x)

ALGORITHM:

step-1: Assume that a root of f(x) lies in the interval I = [a, b].
step-2: Bisect the interval I at m = (a + b)/2 
step-3: Now update interval I as I = [a, m] if f(a)f(b) < 0; if not then update I as I = [m, b]
And it goes on........

Output: -Root(s) of F(x).
*/

#include <stdio.h> //Includes standard I/O libraries
#include <stdlib.h> //Includes standard libraries
#include <math.h> //Includes maths functions

//Function prototypes
float f(float val); //Returns the function value 
void bisection(float a, float b);

//Main function starts here
int main()
{
//Declaration of varibles
  float a, b;
//a - Lower boundary of the interval
//b - Upper boundary of the interval

//Getting the values of a
  printf("Enter a: ");
  scanf("%f", &a);

//Getting the values of a
  printf("Enter b: ");
  scanf("%f", &b);

  bisection(a, b); //Calling bisection function

  exit (0);
}

void bisection(float a, float b)
{
  int i = 0; //To record the numer of iterations taken by the program
  float m; //Mid point of a and b
  float x, y; //Used to store the rounded values of a and b

//Calculating f(a)f(b) to check if the equation has roots in the given interval
  if(f(a)*f(b) >= 0)
  {
      printf("The function has no solutions in the given interval\n");
      exit (1);
  }

//Loop infinitely
  while(1)
  {
      m = (a + b)/2; //Bisecting the interval

      //Checking if m is a root of the equation
      if(f(m) == 0)
      {
          printf("Root %f found after %d iterarions\n", m, i);
	  break;
      }

      //Shriking the interval
      //If f(a)f(m) is -ve, then root exists in the interval [a, m]
      if(f(a)*f(m) < 0)
      {
          b = m;
      }
      //If f(a)f(m) is +ve, then root exists in the interval [m, b]
      else
      {
          a = m;
      }

      //Checking if the equation is converged
      //We can check a == b directly but here 
      //a and b will get rounded off upto 5 digit accuracy
      //to avoid infinite looping
      
      //Round off the values of a and b to 5 digit accuracy
      x = round(a*100000)/100000;
      y = round(b*100000)/100000;
      if(x == y)
      {
          printf("Root %f found after %d iterarions\n", a, i);
	  break;
      }
      i++; //update the number of iteration

  }

  exit (0);
}

//Evaluting the function value
float f(float val)
{
  float ans;
//Calculating function value
  ans = val*log10f(val) - 1.2;
  return ans;
}
