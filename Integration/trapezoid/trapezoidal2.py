#!/usr/bin/python3

import math

def f(x) :
    #ans = math.sqrt(1 + x**2)
    ans = 0.2 + 25*x + 3*x*x
    #ans = 1/(1 + x**2)
    #ans = x*(2 + x**3)
    return ans

# I = (h/2)*(f(x0) + 2(f(x1)+f(x2)+...+f(xn-1)) + f(xn))
# Here x0 is 'a' and xn is 'b'
# And Xi is obtained by Xi = X0 + i*h
def trapezoidal(a, b, h) :
    N = (b - a)/h
    ans = 0
    i = 1

#Inside this while loop, 2[f(x1) + f(x2) + ..... + f(xn-1)] is calculated
    while i < N :
        x = a + i*h
        ans += f(x)
        i += 1
    ans *= 2 # Multiply the obtained value with 2
    ans += (f(a) + f(b)) # Add f(a) + f(b) to that
    ans *= (h/2) # Multiply the entire value with h/2

    return ans

vals = input("Enter a, b and h: ").split()
a = float(vals[0])
b = float(vals[1])
h = float(vals[2])

integral = trapezoidal(a, b, h)
print("Print integral of f(x) on [a, b] is: ", integral)
