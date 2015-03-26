# coding: utf-8
n = int(input())
x = [int(i) for i in input().split()]
y = [int(i) for i in input().split()]
if len(set(x[1:]+y[1:])) < n:
    print('Oh, my keyboard!')
else:
    print('I become the guy.')
