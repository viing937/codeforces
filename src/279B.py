# coding: utf-8
n, t = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
start = 0
end = 0
sumtime = 0
ans = 0
for i in range(n):
    sumtime += a[i]
    end = i+1
    while start<end and sumtime > t:
        sumtime -= a[start]
        start += 1
    if end-start > ans:
        ans = end-start
print(ans)
