# coding: utf-8
n = int(input())
a = [int(i) for i in input().split()]
ans = 0
for i in range(n):
    if a[i] == i:
        ans += 1
if ans == n:
    print(ans)
    exit()
for i in range(n):
    if a[i] != i:
        if a[a[i]] == i:
            print(ans+2)
            break
else:
    print(ans+1)
