# coding: utf-8
n = int(input())
s = [int(i) for i in input().split()]
li = []
for i in range(1,n+1):
    li.append([s[i-1],i])
li.sort()
ans = [[str(i[1]) for i in li]]
for i in range(n-1):
    if li[i][0]==li[i+1][0]:
        li[i], li[i+1] = li[i+1], li[i]
        ans.append([str(i[1]) for i in li])
        if len(ans) >= 3:
            break
if len(ans)>=3:
    print('YES')
    print(' '.join(ans[0]))
    print(' '.join(ans[1]))
    print(' '.join(ans[2]))
else:
    print('NO')
