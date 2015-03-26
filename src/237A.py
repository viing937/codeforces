# coding: utf-8
n = int(input())
cnt = 0
ans = 0
pre = ''
for i in range(n):
    s = input()
    if s == pre:
        cnt += 1
    else:
        if cnt > ans:
            ans = cnt
        cnt = 1
        pre = s
if cnt > ans:
    ans = cnt
print(ans)
