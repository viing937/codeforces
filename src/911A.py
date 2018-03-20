n = int(input())
a = list(map(int, input().split()))

minimum = min(a)
r, last = n, a.index(minimum)
for i in range(last+1, n):
    if a[i] == minimum:
        r = min(r, i-last)
        last = i
print(r)
