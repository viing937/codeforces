n = int(input())
a = list(map(int, input().split(' ')))

ans = []

s = 0
mark = set([a[0]])
for i in range(1, n):
    if a[i] in mark:
        mark = set()
        ans.append([s+1, i+1])
        s = i+1
    else:
        mark.add(a[i])

if len(ans) == 0:
    print(-1)
else:
    ans[-1][1] = n
    print(len(ans))
    for line in ans:
        print(line[0], line[1])
