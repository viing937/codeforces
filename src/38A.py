# coding: utf-8
n = int(input())
d = [int(i) for i in input().split()]
a, b = [int(i) for i in input().split()]
print(sum(d[a-1:b-1]))
