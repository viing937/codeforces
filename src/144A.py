# coding: utf-8
n = int(input())
a = [int(i) for i in input().split()]
cnt = 0
min_height = min(a)
max_height = max(a)
for i in range(n):
    if a[i] == max_height:
        cnt += i
        del(a[i])
        a.insert(0, max_height)
        break
for i in range(n-1, -1, -1):
    if a[i] == min_height:
        cnt += n-i-1
        del(a[i])
        a.insert(-1, max_height)
        break
print(cnt)
