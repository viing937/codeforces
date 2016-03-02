n, p = map(int, input().split(' '))

lines = [list(map(int, input().split(' '))) for i in range(n)]
porb = [(r//p-(l-1)//p)/(r-l+1) for l, r in lines]
ans = sum([(1-(1-porb[i])*(1-porb[i-1])) for i in range(n)])*2000

print(ans)
