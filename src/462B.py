# coding: utf-8
from collections import Counter
n, k = [int(i) for i in input().split()]
card = input()
c = Counter(card)
ans = 0
while k > 0:
    tmp = c.pop(c.most_common(1)[0][0])
    if k > tmp:
        ans += tmp*tmp
        k -= tmp
    else:
        ans += k*k
        k = 0
print(ans)
