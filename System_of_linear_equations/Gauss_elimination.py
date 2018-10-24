#!/usr/bin/python3

import numpy as np

# Order of the matrix
n = int(input('Enter the order of the matrix: '))

# Initially fill the matrix with 0's
matrix = np.zeros([n, n+1])
a = matrix

# Prompt the user for the entries of the matrix.
for i in range(n) :
    for j in range(n+1) :
        print('Enter A[',i+1,',',j+1,']: ', end='', sep='')
        a[i, j] = float(input())


