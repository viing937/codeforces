n, k = map(int, input().split(' '))

a = [[] for i in range(n)]

t = 1
for i in range(n):
    for j in range(k-1):
        a[i].append(t)
        t += 1
for i in range(n):
    for j in range(k-1, n):
        a[i].append(t)
        t += 1

print(sum([a[i][k-1] for i in range(n)]))
for i in range(n):
    print(' '.join(map(str, a[i])))
