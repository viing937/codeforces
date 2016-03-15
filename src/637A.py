n = int(input())
a = list(map(int, input().split(' ')))

c = {}
for i in range(n):
    if a[i] not in c:
        c[a[i]] = [0, 0, a[i]]
    c[a[i]][0] -= 1
    c[a[i]][1] = i

print(sorted(c.values())[0][-1])
