# coding: utf-8
s = list(input())
s.reverse()
ans = 0
while s:
    ans += 1
    hold = s[-1]
    cnt = 0
    while cnt<5 and s and s[-1]==hold:
        cnt += 1
        s.pop()
print(ans)
