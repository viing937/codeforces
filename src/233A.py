# coding: utf-8
n = int(input())
if n%2==1:
    print(-1)
else:
    print(' '.join([str(i+1) if i%2==1 else str(i-1) for i in range(1,n+1)]))
