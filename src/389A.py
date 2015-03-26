# coding: utf-8
n = int(input())
x = [int(i) for i in input().split()]
while True:
    tmp = min(x)
    for i in range(n):
        if x[i]%tmp == 0:
            x[i] = tmp
        else:
            x[i] %= tmp
    if sum(x) == tmp*n:
        break
print(sum(x))
