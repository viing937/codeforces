# coding: utf-8
n, k = [int(i) for i in input().split()]
print(' '.join([str(n+1-i) if i<=k else str(i-k) for i in range(1,n+1)]))
