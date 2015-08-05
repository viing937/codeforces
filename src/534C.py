n, A = [int(i) for i in input().split()]
d = [int(i) for i in input().split()]
s = sum(d)
ans = []
for dd in d:
    left = max(0, A-s+dd)
    right = min(dd, A-n+1)
    cnt = 0
    if left > 1:
        cnt += left-1
    if right < dd:
        cnt += dd-right
    ans.append(cnt)
print(' '.join([str(i) for i in ans]))
