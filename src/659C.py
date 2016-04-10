n, m = map(int, input().split(' '))
a = set(map(int, input().split(' ')))

ans = []
k = 1
while m >= k:
    if k not in a:
        m -= k
        ans.append(str(k))
    k += 1

print(len(ans))
print(' '.join(ans))
