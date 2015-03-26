# coding: utf-8
n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
a.reverse()
ans = 0
while a:
    tmp = m
    while a and tmp>=a[-1]:
        tmp -= a.pop()
    ans += 1
print(ans)
