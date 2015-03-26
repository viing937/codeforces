# coding: utf-8
n, m, a, b = [int(i) for i in input().split()]
print(min(n//m*b+n%m*a, (n+m-1)//m*b, n*a))
