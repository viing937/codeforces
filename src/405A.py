# coding: utf-8
n = int(input())
a = [int(i) for i in input().split()]
a = [str(i) for i in sorted(a)]
print(' '.join(a))
