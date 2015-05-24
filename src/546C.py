from collections import deque
n = int(input())
a = deque([int(i) for i in input().split()[1:]])
b = deque([int(i) for i in input().split()[1:]])
mark = set()
ans = 0
while a and b:
    if str(a)+str(b) in mark:
        print(-1)
        exit()
    mark.add(str(a)+str(b))
    ans += 1
    aa = a.popleft()
    bb = b.popleft()
    if aa > bb:
        a.append(bb)
        a.append(aa)
    else:
        b.append(aa)
        b.append(bb)
if a:
    print(ans,1)
else:
    print(ans,2)
