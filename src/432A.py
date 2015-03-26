# coding: utf-8
n, k = [int(i) for i in input().split()]
y = [int(i) for i in input().split()]
sumsum = 0
for i in range(6-k):
    sumsum += y.count(i)
print(sumsum//3)
