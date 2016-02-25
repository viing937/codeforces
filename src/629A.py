n = int(input())

c = [list(input()) for i in range(n)]

ans = 0

for i in range(n):
    t = c[i].count('C')
    ans += t*(t-1)//2

c = list(zip(*c))

for i in range(n):
    t = c[i].count('C')
    ans += t*(t-1)//2

print(ans)
