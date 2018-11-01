/* Simpson’s 1/3 Rule
    The trapezoidal  rule  was  based  on  approximating  the  integrand  by  a  first  order  polynomial, and  then  integrating  the  polynomial  over 
interval  of  integration.    Simpson’s  1/3  rule  is  an extension  of  Trapezoidal  rule  where  the  integrand  is  approximated  by  a  second  order  
polynomial 
    I = ∫f(x)dx from a to b
    where 
         a = lower limit of the integration
         b = upper limit of the integration.

    ∫f(x)dx from a to b = (h/3)(f(x0)+4f(x1)+2f(x2)+....+f(x2N))
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
float simpson(int n, float h, float a, float b);
float f(float x);

int main(int argc, char **argv)
{
   int  n;
   float  a, b, h;
   // n - Number of intervals
   // a - lower limit of the interval
   // b - upper limit of the interval

   printf("Enter the interval: ");
   scanf("%f%f", &a, &b);
   printf("Enter the value of h: ");
   scanf("%f", &h);

   // Calculate the value of n
   n = (b-a)/(2*h);

   //Invoking the simpson function
   simpson(n, h, a, b);
   exit(0);
}

float simpson(int n, float h, float a, float b)
{
   int  i = 1, N = (2*n);
   float px = 0;

   px += f(a); //Calling function
   //printf("x0 = %f and f(x%d) = %f\n", a, i, function(a));
   while (i < N)
   {
      if (i%2 == 1)  //Check condition
      {
         px += 4*f(a+i*h);  //Calling function
      }
      else if (i%2 == 0)  //Check condition
      {
         px += 2*f(a+i*h);  //Calling function
      }
      i++;
   }
   //printf("x%d = %f and f(x%d) = %f\n", N, b, N, function(b));
   px += f(b);

   px = (h*px)/3;
   printf("Value of integral between [%.1f, %.1f] is %f\n", a, b, px);

   return px;
}

float f(float x)
{
   float ans;

   //calculating the function value
   ans = x*(1-(x*x));

   return ans; 
}
