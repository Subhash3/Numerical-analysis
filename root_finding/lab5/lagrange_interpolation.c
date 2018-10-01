/*
Given a set of k + 1 data points 
       (x_{0},y_{0}),......,(x_{j},y_{j}),.....,(x_{k},y_{k})
       where no two xj x_{j} x_{j} are the same, the interpolation polynomial in the Lagrange form is a linear combination

       p(x) = li(x) * f(xi)
       where li(x) = w(x)/(x-xi)w'(xi)

       w(x) = (x-x0)(x-x1)(x-x2).............(x-xn)
       w'(x) = (xi-x0)(xi-x1)(xi-x2)......(xi-x_{i-1})(xi-x_{i+1})......(xi-xn)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//All constant definitions
#define MAX  150

//Function prototypes
float lagrange(float x[], float y[], int nitems, float xi);

int main(void)
{
   float x[MAX], y[MAX], xi, f;
   int i, nitems;
   char xs[MAX], ys[MAX];
   printf("Enter the value of x and y as inputs and then the value of xi.\nIf you are done by entering the polynomial terms then type any lower case letter to terminate the input process.\n\n");

   // Loop infinitely
   while(1)
   {
      printf("Enter the value of x: ");
      scanf("%s", xs);

      //Checking exit conditions
      if (*xs >= 'a' && *xs <= 'z')
      {
          break;
      }

      printf("Enter the value of f(x): ");
      scanf("%s", ys);
      if (*ys >= 'a' && *ys <= 'z')
      {
          fprintf(stderr, "These values for f(x) can't be accepted as input.\n");
          exit(2);
      }
      printf("\n");

      // Converting the provided strings to floats
      x[i] = atof(xs);
      y[i] = atof(ys);

      i++;
      nitems++;
   }

   printf("Enter the value of at whose function value is to be found: ");
   scanf("%f", &xi);

   // Invoking the lagrange function
   f = lagrange(x, y, nitems, xi);
   printf("\nFunction value at %f is: %f\n", xi, f);
   exit(0);
}

float lagrange(float x[], float y[], int nitems, float xi)
{
   float w = 1, dw = 1, pxi = 0, lx[MAX];
   int i, j;

   for (i = 0; i < nitems; i++)
   {
       // Calculating the value of w(x) at xi
       w = w * (xi - x[i]);
   }

   i = 0;
   while (i < nitems)
   {
      for (j = 0; j < nitems; j++)
      {
         if (j == i)
         {
            continue;  //Skipping to next term
         }
	 //calculating the value of w'(x) at x = xi
         dw = dw * (x[i] - x[j]);
      }

      // calculating the value of li(xi)
      lx[i] = (w / ((xi - x[i]) * dw));
      dw = 1;
      i++;
   }

   for (i = 0; i < nitems; i++)
   {
      pxi = pxi + lx[i] * y[i];  //Calculating the value of p(x) at xi
   }

   return pxi;
}
