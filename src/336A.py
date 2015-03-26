# coding: utf-8
x, y = [int(i) for i in input().split()]
length = abs(x)+abs(y)
ans = []
if x < 0:
    ans.append([-length,0])
else:
    ans.append([length,0])
if y < 0:
    ans.append([0,-length])
else:
    ans.append([0,length])
ans.sort()
print(ans[0][0],ans[0][1],ans[1][0],ans[1][1])
