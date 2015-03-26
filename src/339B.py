# coding: utf-8
n, m = [int(i) for i in input().split()]
current = 1
ans = 0
for des in input().split():
    des = int(des)
    if des >= current:
        ans += des-current
    else:
        ans += des-current+n
    current = des
print(ans)
