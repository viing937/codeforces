# coding: utf-8
n = int(input())
s = input()
ans = 0
flag = 1 
for ch in s:
    if ch == '0' and flag == 1:
        ans += 1
        flag = 0
    elif flag == 1:
        ans += 1
print(ans)
