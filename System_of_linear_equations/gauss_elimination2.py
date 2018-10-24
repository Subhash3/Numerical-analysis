#!/usr/bin/python3

import numpy as np

n = int(input('Enter the order of the matrix: '))
A = np.zeros((n+1, n+1))
x = list()
for i in range(1, n+1) :
    for j in range(1, n+1) :
        print("A[",i,"]","[",j,"]", sep='',end=":")
        A[i][j] = input()

for j in range(1, n+1) :
    for i in range(1, n+1) :
        if i > j :
            c = A[i][j]/A[j][j]
            for k in range(1, n+1) :
                A[i][k] = A[i][k] - c*A[j][k]

x[n] = A[n][n+1]/A[n][n]

for i in range(n-1, 0, -1) :
    total = 0
    for j in range(i + 1, n+1) :
        total = total  + A[i][j]*x[j]
    x[i] =(A[i][n+1]-total)/A[i][j]
print("Solution: ")
for i in range(1, n+1) :
    print(x[i])
