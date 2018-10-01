#!/usr/bin/python3

import math
import matplotlib.pyplot as plt

def f(x) :
    return x**2 - 4*x + 4

def df(x) :
    return 2*x - 4

x = [i for i in range(-100, 100)]
y = [f(j) for j in x]
plt.plot(x, y)
plt.show()
def newton(guess) :
    while True :
        root = guess - (f(guess)/df(guess))
        plt.plot(guess, root)
        #print("checking: ", root)
        #print("guess: ", guess)
        if f(root) == 0 :
            return root
        if (root*100000)/100000 == (guess*100000)/100000 :
            return root
        guess = root

guess = float(input("Enter the guess: "))
root = newton(guess)
print(root)
