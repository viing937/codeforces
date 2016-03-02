n, p = map(int, input().split(' '))

s = [0]*n
for i in range(n):
    l, r = map(int, input().split(' '))
    s[i] = (r//p*p-(l-1)//p*p)/p/(r-l+1)

ans = 0
for i in range(n):
    ans += (1-(1-s[i])*(1-s[i-1]))*2000

print(ans)
