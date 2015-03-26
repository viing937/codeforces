# coding: utf-8
n, x = [int(i) for i in input().split()]
sumsum = 0
for i in input().split():
    sumsum += int(i)
print((abs(sumsum)+x-1)//x)
