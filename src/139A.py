# coding: utf-8
n = int(input())
a = [int(i) for i in input().split()]
n = (n-1)%sum(a)+1
ans = 0
while n:
    if n > a[ans]:
        n -= a[ans]
    else:
        n = 0
    ans += 1
print(ans)
