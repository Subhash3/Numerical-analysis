#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x, float y);

int main()
{
  float x0, y0, y, h;
  int i, iter;

  printf("Enter x0: ");
  scanf("%f", &x0);
  printf("Enter y0: ");
  scanf("%f", &y0);
  printf("Enter h: ");
  scanf("%f", &h);
  printf("Enter the number of iterations: ");
  scanf("%d", &iter);

  i = 1;
  while(1)
  {
      y = h*f(x0, y0) + y0;
      y0 = y;
      x0 = x0 + h;
      printf("y%d: %f\n", i, y);
      if(i == iter)
      {
          break;
      }
      i++;
  }
  exit (0);
}

float f(float x, float y)
{
  return x + y;
}
