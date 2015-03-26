# coding: utf-8
m, n = [int(i) for i in input().split()]
area = m*n

if area%2 == 1:
    area = area-1

print(area//2)
