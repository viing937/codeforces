# coding: utf-8
n, d = [int(i) for i in input().split()]
ans = (d-sum([int(i) for i in input().split()]))//5
if ans >= (n-1)*2:
    print(ans)
else:
    print(-1)
