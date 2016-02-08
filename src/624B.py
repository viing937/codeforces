n = int(input())
a = list(map(int, input().split(' ')))
a.sort(reverse = True)
for i in range(1, n):
    if a[i] >= a[i-1]:
        a[i] = a[i-1]-1
    if a[i] < 0:
        a[i] = 0
print(sum(a))
