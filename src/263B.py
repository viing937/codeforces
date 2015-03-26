# coding: utf-8
n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
a.sort(reverse=True)
if k == 0:
    print(a[0]+1,0)
elif k > n:
    print(-1)
else:
    print(a[k-1],0)
