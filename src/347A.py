# coding: utf-8
n = int(input())
a = [int(i) for i in input().split()]
index = a.index(max(a))
a[0], a[index] = a[index], a[0]
index = a.index(min(a))
a[-1], a[index] = a[index], a[-1]
a = [a[0]] + sorted(a[1:-1]) + [a[-1]]
print(' '.join([str(i) for i in a]))
