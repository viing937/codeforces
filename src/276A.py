# coding: utf-8
n, k = [int(i) for i in input().split()]
ans = []
for i in range(n):
    f, t = [int(i) for i in input().split()]
    if t > k:
        ans.append(f-t+k)
    else:
        ans.append(f)
print(max(ans))
