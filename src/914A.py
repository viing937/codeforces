n = int(input())
a = list(map(int, input().split()))
r = max(filter(lambda x: x < 0, a + [-1000001]))
for t in filter(lambda x: x > 0, a):
    if pow(int(t ** 0.5), 2) != t:
        r = max(r, t)
print(r)
