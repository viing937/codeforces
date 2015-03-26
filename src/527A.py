# coding: utf-8
a, b = [int(i) for i in input().split()]
ans = 0
while a%b!=0:
    ans += a//b
    a, b = b, a%b
ans += a//b
print(ans)
