# coding: utf-8
n = int(input())
id = [int(i) for i in input().split() if i!='0']
id.sort()
ans = 0
while id:
    tmp = id.pop()
    if id and tmp == id[-1]:
        ans += 1
        id.pop()
    if id and tmp == id[-1]:
        ans = -1
        break
print(ans)
