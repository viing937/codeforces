# coding: utf-8
n = int(input())
t = 0
cnt = 0
for i in input().split():
    if i == '-1':
        if t == 0:
            cnt += 1
        else:
            t -= 1
    else:
        t += int(i)
print(cnt)
