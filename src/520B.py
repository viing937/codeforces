# coding: utf-8
from collections import deque
n, m = [int(i) for i in input().split()]
ans = [-1]*((n+m)*2+1)
ans[m] = 0
queue = deque([m])
while queue:
    k = queue.popleft()
    if ans[k+1] == -1:
        ans[k+1] = ans[k]+1
        queue.append(k+1)
    if not k%2 and ans[k//2] == -1:
        ans[k//2] = ans[k]+1
        queue.append(k//2)
    if k == n:
        break
print(ans[k])
