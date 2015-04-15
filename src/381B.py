from collections import deque
m = int(input())
b = [int(i) for i in input().split()]
b.sort(reverse=True)
ans = deque()
ans.append(b[0])
for i in b[1:]:
    if i < ans[-1]:
        ans.append(i)
    elif i < ans[0]:
        ans.appendleft(i)
print(len(ans))
print(' '.join([str(i) for i in ans]))
