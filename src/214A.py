# coding: utf-8
import math
n, m = [int(i) for i in input().split()]
if n > m:
    n, m = m, n
ans = 0
for a in range(int(math.sqrt(n))+1):
    b = n-a*a
    if a + b*b == m:
        ans += 1
print(ans)
