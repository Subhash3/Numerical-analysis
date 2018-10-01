#!/usr/bin/python3

import matplotlib.pyplot as plt

def f(x) :
    ans = x*x - 4*x + 4
    return ans

def df(x) :
    ans = 2*x
    return ans

x = [i for i in range(-10, 10)]
y = [f(j) for j in x]

plt.plot(x, y)
plt.show()
