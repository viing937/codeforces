n = int(input())
a = sorted(map(int, input().split(' ')))

ans = [0]*n
for i in range(n):
    ans[i] = a[i//2] if i%2 == 0 else a[(i+n)//2]

print(' '.join(map(str, ans)))
