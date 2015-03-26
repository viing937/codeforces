# coding: utf-8
n, x, y = [int(i) for i in input().split()]
ans = int((y/100*n)-x)
if (ans+x)/n < y/100:
    ans += 1
if ans > 0:
    print(ans)
else:
    print(0)
