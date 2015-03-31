# coding: utf-8
n, k = [int(i) for i in input().split()]
h = [int(i) for i in input().split()]
minsum = sum(h[:k])
thissum = minsum
ans = 0
for i in range(k,n):
    thissum += h[i]
    thissum -= h[i-k]
    if thissum < minsum:
        thissum = minsum
        ans = i-k+1
print(ans+1)
