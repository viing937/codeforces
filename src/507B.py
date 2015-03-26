# coding: utf-8
import math
r, x, y, xx, yy = [int(i) for i in input().split()]
dis = math.sqrt(abs(xx-x)*abs(xx-x)+abs(yy-y)*abs(yy-y))
ans = int(dis/2/r)
if ans < dis/2/r:
    ans += 1
print(ans)
