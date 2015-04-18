m, n = [int(i) for i in input().split()]
ans = 0
for i in range(1,m+1):
    tmp_a = pow(i/m,n)
    tmp_b = pow((i-1)/m,n)
    ans += i*(tmp_a-tmp_b)
print(ans)
