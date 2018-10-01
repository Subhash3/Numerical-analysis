#!/usr/bin/python3

import math

def f(x) :
    ans = x*(1 - x*x)
    return ans

# I = (h/n)[f(x0) + 4[f(x1) + f(x3) + .... + f(x2n-1)] + 2[f(x2) + f(x4) +.....+ f(x2n-2))] + f(xn)]
# I = (h/n)(f(x0) + f(x2n) + 4p + 2q)

def simphson(a, b, h) :
    N = (b - a)/(2*h)
    ans = 0

    i = 1
    p = 0
    while i < 2*N :
        x = a + i*h
        p += f(x)
        i += 2

    q = 0
    i = 2
    while i < 2*N :
        x = a + i*h
        q += f(x)
        i += 2

    ans += (h*(f(a) + 4*p + 2*q + f(b)))/2
    return ans

vals = input("Enter a, b and h: ").split()
a = float(vals[0])
b = float(vals[1])
h = float(vals[2])
integral = simphson(a, b, h)
print(integral)


