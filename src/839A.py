n, k = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
acc = 0
for i in range(n):
    acc += a[i]
    k -= min(8, acc)
    acc -= min(8, acc)
    if k <= 0:
        print(i+1)
        exit()
print(-1)
