# coding: utf-8
n, k = [int(i) for i in input().split()]
ans = 0
for i in range(n):
    mark = set()
    s = [int(i) for i in input()]
    for digit in s:
        if digit<=k:
            mark.add(digit)
    if len(mark)==k+1:
        ans += 1
print(ans)
