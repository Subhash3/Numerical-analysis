#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x, float y);

int main()
{
  int i, iter;
  float x0, y0, h;

  printf("Enter x0: ");
  scanf("%f", &x0);
  printf("Enter y0: ");
  scanf("%f", &y0);
  printf("Enter h: ");
  scanf("%f", &h);
  printf("Enter the number of iteration: ");
  scanf("%f", &iter);

  while(1)
  {
      y = y0 + f(x0, y0)*h;
      printf("y: %f\n", y);

      for(j = 0; j < 10; j++)
      {
          y = y0 + 
      }
  }
}

float f(float x, float y)
{
  
}
