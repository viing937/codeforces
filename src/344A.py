# coding: utf-8
n = int(input())
cnt = 1
pre = input()
for i in range(n-1):
    now = input()
    if int(pre)+int(now)==11:
        cnt += 1
    pre = now
    
print(cnt)
