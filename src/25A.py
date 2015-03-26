# coding: utf-8
n = int(input())
li = [int(i) for i in input().split()]
cnt = [0]*2
for i in li[:3]:
    cnt[i%2] += 1
if cnt[1] > 1:
    for i in range(n):
        if li[i]%2 == 0:
            print(i+1)
            break
else:
    for i in range(n):
        if li[i]%2 == 1:
            print(i+1)
            break
