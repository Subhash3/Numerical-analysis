#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function prototypes
float f(float x);
float simphson(float a, float b, float h);

int main()
{
  float a, b, h, integral;

  printf("Enter a, b, and h: ");
  scanf("%f %f %f", &a, &b, &h);

  integral = simphson(a, b, h);
  printf("%f\n", integral);

  exit (0);
}

float simphson(float a, float b, float h)
{
  int N, i;
  float ans, x;

  N = (b - a)/(h);
  printf("N: %d\n", N);
  if(N % 2 == 1)
  {
      printf("Number of intervals should be even..Try changing h value.\n");
      exit (1);
  }

  ans = 0;
  i = 0;
  while (i <= 2*N)
  {
      //printf("i = %d\n", i);
      x = a + i*h;
      if(i == 0 || i == 2*N)
      {
          ans += f(x);
	  i++;
	  continue;
      }
      if(i % 2 == 0)
      {
          ans += 2*f(x);
      }
      else
      {
          ans += 4*f(x);
      }
      i++;
  }
  //ans += f(a) + f(b);
  ans *= h/N;
  return ans;
}

float f(float x)
{
  float ans;

  ans = x*(1 - x*x);
  return ans;
}
