# coding: utf-8
a, m = [int(i) for i in input().split()]
loop = set() 
while a%m not in loop:
    loop.add(a%m)
    a += a%m
if 0 in loop:
    print('Yes')
else:
    print('No')
