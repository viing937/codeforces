n = int(input())
f = {}
ans = set()
for i in range(n):
    tmp = input().split()
    if tmp[0] not in f.values():
        ans.add(tmp[0])
    f[tmp[0]] = tmp[1]
print(len(ans))
for old in ans:
    new = old
    while new in f.keys():
        new = f[new]
    print(old, new)
