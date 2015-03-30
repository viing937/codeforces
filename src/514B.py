# coding: utf-8
n, x0, y0 = [int(i) for i in input().split()]
ans = 0
points = set() 
for i in range(n):
    tmp = [int(j) for j in input().split()]
    if tmp[1]==y0:
        ans = 1
    else:
        points.add((tmp[0]-x0)/(tmp[1]-y0))
ans += len(points)
print(ans)
