# coding: utf-8
n, d = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
m = int(input())
a.sort()
if m<=n:
    print(sum(a[:m]))
else:
    print(sum(a)-(m-n)*d)
