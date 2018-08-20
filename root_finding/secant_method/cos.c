#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function prototypes
float f(float x);
float secant(float a, float b);

int main()
{
  float a, b, root;

  printf("Enter a: ");
  scanf("%f", &a);
  printf("Enter b: ");
  scanf("%f", &b);

  root = secant(a, b);

  printf("Root of the equation is %f\n", root);

  exit (0);
}

float f(float x)
{
  float ans;

  ans = 3*x - cosf(x) - 1;

  //Checking if result is NAN
  if (ans != ans)
  {
      printf("Cannot proceed further...Try changing the inteval\n");
      exit (2);
  }

  return ans;
}

float secant(float a, float b)
{
  float c;

  while (1)
  {
      c = (a*f(b) - b*f(a))/(f(b) - f(a));

      if(f(c) == (float)0)
      {
          return c;
      }

      if(b == c)
      {
          return c;
      }
      a = b;
      b = c;
  }
}
