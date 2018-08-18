#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function prototypes
float f(float x);
float df(float x);
float newton(float a);

int main()
{
  float root, a;

  printf("Enter initial guess: ");
  scanf("%f", &a);

  root = newton(a);
  printf("Root of the equation is %f\n", root);

  exit (0);
}

float newton(float a)
{
  float root, x, y;

  while(1)
  {
      root = a - (f(a)/df(a));

      printf("Checking %f\n", root);
      if(f(root) == 0)
      {
          return root;
      }

      x = (root*100000)/100000;
      y = (a*100000)/100000;

      if(x == y)
      {
          return root;
      }
      a = root;
  }
}

float f(float x)
{
  float ans;

  ans = (1 + cosf(x))/3;
  if(ans != ans)
  {
      printf("Couldn't proceed,..Try changing value\n");
      exit (2);
  }
  return ans;
}

float df(float x)
{
  float ans;

  ans = -sinf(x)/3;

  if(ans != ans)
  {
      printf("Couldn't proceed,..Try changing value\n");
      exit (2);
  }
  return ans;
}
