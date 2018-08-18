/*To find the roots of the equation f(x) = 0 by successive approximations,
we write it in the form x = p(x). The roots of f(x) = 0 are the same as the points of intersection of the straight line y = x and the curve representing y = p(x).

Let X = X0 be an initial approximation of the desired root, then the first approximation x1 is given by X1 = p(X0). Now, treating x1 as the initial value, the second approximation is X2 = p(X1). Proceeding in this way the nth approximation is given by Xn = p(Xn-1)

The equation Xk+1 = (1 + cos(Xk))/3 is used to find the roots of the equation F(x) = 1 + cos(x) - 3x.

In this method we use X0 as initial value to find X1 using X1 = (1 + cos(X0))/3, then X2 is calculated using X2 = (1 + cos(x))/3 and the process goes on.....

Finally we find the value of X for which x = (1 + cos(x))/3, and that is the point of convergence of the equation F(x) = 1 + cos(x) - 3x.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cos_eq(double guess);

int main(int argc, char **argv)
{
  if(argc != 2)
  {
      printf("USAGE: %s <guess>\n", argv[0]);
      exit (0);
  }
  float guess;

  guess = atof(argv[1]);
  cos_eq(guess);

  exit (0);
}

//Xk+1 = (1 + cos(Xk))/3
void cos_eq(double guess)
{
  int i = 1; //To record the number of iterations
  double root, x; //x is Xk and root is Xk+1
  x = guess; //Initializing Xk with guess 

  printf("F(x) = 1 + cos(x) - 3x.\n");
  //Loop infinitely
  while(1)
  {
      //printf("checking: %f\n", x);
      root = (1 + cos(x))/3; //Substitute the values in the equation
      if(root == x) //If the Root converges, then break out
      {
          printf("After %d iterations root %f found\n", i, root/100000000);
	  break;
      }
      //If loop goes infinitely, then break after 100000 iterations
      if(i > 100000)
      {
          printf("Root of F(x) might be around %lf\n", root);
	  exit (0);
      }
      x = root;
      i++;
  }
  return;
}
