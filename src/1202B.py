from collections import deque
from functools import lru_cache


@lru_cache(maxsize=None)
def helper(a, b):
    m = {}
    queue = deque([(0, 0)])
    while queue:
        cur, cnt = queue.popleft()
        cura = (cur+a) % 10
        curb = (cur+b) % 10
        if cura not in m:
            m[cura] = cnt + 1
            queue.append((cura, cnt + 1))
        if curb not in m:
            m[curb] = cnt + 1
            queue.append((curb, cnt + 1))
    return m


s = list(map(int, input()))
ans = [[0] * 10 for i in range(10)]

for i in range(10):
    for j in range(i, 10):
        m = helper(min(i, j), max(i, j))
        cnt = 0
        for k in range(len(s)-1):
            dis = ((s[k+1] - s[k]) % 10 + 10) % 10
            if cnt == -1 or dis not in m:
                cnt = -1
            else:
                cnt += m[dis] - 1
        ans[i][j] = cnt
        ans[j][i] = cnt

for i in range(10):
    print(' '.join(map(str, ans[i])))
