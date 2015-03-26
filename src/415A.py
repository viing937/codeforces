# coding: utf-8
n, m = [int(i) for i in input().split()]
lights = [0]*(n+1)
b = [int(i) for i in input().split()]
for i in b:
    for j in range(i,n+1):
        if lights[j]==0:
            lights[j] = i
print(' '.join([str(i) for i in lights[1:]]))
