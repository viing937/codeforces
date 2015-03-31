# coding: utf-8
import math
n, k = [int(i) for i in input().split()] 
x, y = [int(i) for i in input().split()]
dis = 0
for i in range(n-1):
    xx, yy = [int(i) for i in input().split()]
    dis += math.sqrt(pow(x-xx,2)+pow(y-yy,2))
    x, y = xx, yy
print(dis/50*k)
