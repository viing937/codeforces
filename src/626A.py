n = int(input())
ver, hor = [0], [0]

for ch in input():
    ver.append(ver[-1])
    hor.append(hor[-1])
    if ch == 'U':
        ver[-1] += 1
    if ch == 'D':
        ver[-1] -= 1
    if ch == 'L':
        hor[-1] += 1
    if ch == 'R':
        hor[-1] -= 1

ans = 0
for i in range(1, n+1):
    for j in range(i+1, n+1):
        if hor[j]-hor[i-1]==0 and ver[j]-ver[i-1]==0:
            ans += 1
print(ans)
