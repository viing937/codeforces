n, k = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
r = 100
for t in a:
    if k%t == 0 and k//t < r:
        r = k//t
print(r)
