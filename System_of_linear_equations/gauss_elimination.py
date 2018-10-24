#!/usr/bin/python3

import numpy as np

n = int(input('Enter the order of the matrix: '))
a = np.zeros((n, n+1))

for i in range(n) :
    for j in range(n+1) :
        print("a[",i+1,"][",j+1,"]", sep='', end=': ')
        a[i][j] = float(input())

for i in range(n) :
    a[1, i] = a[0, 0]*a[1, i] - a[1, 0]*a[0, i]
    a[2, i] = a[0, 0]*a[2, i] - a[2, 0]*a[0, i]
for i in range(n) :
    a[2, i] = a[1, 1]*a[2, i] - a[2, 1]*a[1, i]
z = a[2, 3]/a[2, 2]
y = 
print(a)
