# coding: utf-8
n = int(input())
a = [int(i)%2 for i in input().split()]
if sum(a)%2==0:
    print(a.count(0))
else:
    print(a.count(1))
