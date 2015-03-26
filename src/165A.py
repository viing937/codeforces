# coding: utf-8
n = int(input())
li = []
for i in range(n):
    li.append([int(j) for j in input().split()])
lx = {}
ly = {}
for p in li:
    if p[1] in lx.keys():
        if p[0]>lx[p[1]][1]:
            lx[p[1]][1] = p[0]
        elif p[0]<lx[p[1]][0]:
            lx[p[1]][0] = p[0]
    else:
        lx[p[1]] = [p[0],p[0]]
    if p[0] in ly.keys():
        if p[1]>ly[p[0]][1]:
            ly[p[0]][1] = p[1]
        elif p[1]<ly[p[0]][0]:
            ly[p[0]][0] = p[1]
    else:
        ly[p[0]] = [p[1],p[1]]
ans = 0
for p in li:
    if p[0] in ly.keys() and p[1]>ly[p[0]][0] and p[1]<ly[p[0]][1]\
   and p[1] in lx.keys() and p[0]>lx[p[1]][0] and p[0]<lx[p[1]][1]:
        ans += 1
print(ans)
