# coding: utf-8
n = int(input())
if n<=2:
    print(-1)
else:
    print(' '.join([str(i) for i in range(2,n+1)]+['1']))
