x1, y1, x2, y2 = map(int, input().split(' '))
if x1 > x2:
    x1, x2 = x2, x1
if y1 > y2:
    y1, y2 = y2, y1

if (x2-x1)%2:
    ans = (x2-x1+1)*(y2-y1+1)//2
else:
    ans = (y2-y1+1)*(x2-x1)//2+(y2-y1)//2+1

print(ans)
