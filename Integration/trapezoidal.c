#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function prototypes
float f(float x); //to calculate the function value at x
float trapezoidal(float a, float b, float h);

int main()
{
  float a, b, h, integral;
  // a : Lower bound of the interval
  // b : Upper bound od the interval
  // h : Length of each interval
  // integral : Finally calculated integral of f(x) on [a, b]

  //Getting the values of a, b, and h
  printf("Enter a, b, and h: ");
  scanf("%f %f %f", &a, &b, &h);

  //Invoking the trapezoidal function
  integral = trapezoidal(a, b, h);
  printf("Integral of f(x) on [a, b] is: %f\n", integral);
  
  exit (0);
}

float trapezoidal(float a, float b, float h)
{
  int N, i;
  float x, ans;
  // N : Number of intervals divided on [a, b], each of length h
  // N = (b - a)/h
  // i is used to calculate the values of each interval
  // Xi = X0 + ih

  ans = 0;
  N = (b - a)/h;
  i = 1; //Initialise i with i
  while(i < N)
  {
      x = a + i*h; //Dividing the interval
      ans += f(x); // calculate the function value
      i++; // Update i
  }
  ans *= 2;
  ans += (f(a) + f(b));
  ans *= h/2;
  return ans;
}

float f(float x)
{
  float ans;

  //Calculating the function value at x
  ans = x*(1 - x*x);
  return ans;
}
