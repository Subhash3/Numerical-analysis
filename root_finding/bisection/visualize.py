#!/usr/bin/python3

import math
import matplotlib.pyplot as plt

def f(x) :
    return x**2 - 3*x - 9

x = [i for i in range(-100, 100)]
y = [f(j) for j in x]
plt.plot(x, y)
#plt.show()

def bisection(a, b) :

    if f(a)*f(b) >= 0 :
       print("No real roots!")
       quit()
    while True :
        m = (a + b)/2
        x = list()
        for i in range(-100, 100) :
                x.append(m)
        y = [i for i in range(-100, 100)]
        plt.plot(x, y)
        if f(m) == 0 :
            return m
        if f(a)*f(m) < 0 :
            b = m
        else :
            a = m
        if int(a * 100000)/100000 == int(b * 100000)/100000 :
            return a

a = float(input("Enter a: "))
b = float(input("Enter b: "))
root = bisection(a, b)
print(root)
plt.show()
