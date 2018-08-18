/*To find the roots of the equation f(x) = 0 by successive approximations,
we write it in the form x = p(x). The roots of f(x) = 0 are the same as the points of intersection of the straight line y = x and the curve representing y = p(x).

Let X = X0 be an initial approximation of the desired root, then the first approximation x1 is given by X1 = p(X0). Now, treating x1 as the initial value, the second approximation is X2 = p(X1). Proceeding in this way the nth approximation is given by Xn = p(Xn-1)

The equation Xk+1 = -c/(a*Xk + b) is used to find the roots of the equation
F(x) = aX^2 + bX + c.

In this method we use X0 as initial value to find X1 using  X1 = -c/(a*X0 + b), then X2 is calculated using  X2 = -c/(a*X1 + b) and the process goes on.....

Finally we find the value of X for which  X = -c/(a*X + b), and that is the point of convergence of the equation F(x) = aX^2 + bX + c.

Similarly we use Xk+1 = (-c/(a*Xk)) - b/a to find the second root of F(x) = aX^2 + bX + c. 

Finally we have two roots of the quadratic equation F(x) = aX^2 + bX + c.
*/


#include <stdio.h>
#include <stdlib.h>

//Function prototypes
void method1(float guess);
void method2(float guess);

//Global variables
float a, b, c;

int main(int argc, char **argv)
{
  if(argc != 5)
  {
      fprintf(stderr, "USAGE: %s <a> <b> <c> <guess>\n", argv[0]);
      printf("a := X^2 coefficient\n");
      printf("b := X coefficient\n");
      printf("a := constant\n");
      exit (0);
  }

  float guess, discriminant;
  //char ch;

  //Getting coefficients of quadtratic equation
  a = atof(argv[1]);
  b = atof(argv[2]);
  c = atof(argv[3]);

  //making the guess
  guess = atof(argv[4]);

  //Calculating discriminant
  discriminant = (b*b)-(4*a*c);

  //Checking if discriminant is < 0
  //If discriminant is less than 0, no real roots
  if(discriminant < 0)
  {
      printf("The equation has no real roots\n");
      exit (0);
  }

  method1(guess); //Call method1 function
  method2(guess); //Call method2 function

  exit (0);
}

//Using firt equation
void method1(float guess)
{
  printf("---ROOT 1----\n\n");

  float root, x; //x is Xk and root is Xk+1
  int iterations = 0;
  x = guess; //Initializing x with guess

  //Loop infinitely
  while(1)
  {
      root = -c/(a*x + b); //Substiting values in equation 1
      //printf("Checking: %f\n", root);
      if(root == x) //If the equation converges, then break the out of the loop
      {
          printf("After %d iterations root %f found.\n", iterations + 1, root);
	  break;
      }
      x = root; //Update guess
      iterations += 1;
  }

  return;
}


//Using secong equation
void method2(float guess)
{
  printf("\n---ROOT 2----\n\n");

  float root, x; //x is Xk and root is Xk+1
  int iterations = 0;
  x = guess; //Initializing x with guess

  //Loop infinitely
  while(1)
  {
      root = (-c/(a*x)) - b/a; //Substitute the values in eq 2
      //printf("Checking: %f\n", root);
      if(root == x) //If equation converges then break out of the loop
      {
          printf("After %d iterations root %f found.\n", iterations + 1, root);
	  break;
      }
      x = root; //Update guess
      iterations += 1;
  }

  return;
}

