n = int(input())
a = [list(map(int, input().split(' '))) for i in range(n)]
ans = [0]*n
for i in range(1, n+1):
    for j in range(n):
        if ans[j] == 0 and a[j].count(i) == n-i:
            ans[j] = str(i)
            break
print(' '.join(ans))
