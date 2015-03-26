# coding: utf-8
n = int(input())
ans = 1
while n >= (1+ans)*ans//2:
    n -= (1+ans)*ans//2
    ans += 1
print(ans-1)
