# coding: utf-8
n, s, t = [int(i) for i in input().split()]
p = [0] + [int(i) for i in input().split()]
if s == t:
    print(0)
    exit()
pos = p[s]
ans = 1
while pos != t:
    pos = p[pos]
    ans += 1
    if pos == s:
        print('-1')
        break
else:
    print(ans)
