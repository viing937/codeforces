# coding: utf-8
n, m = [int(i) for i in input().split()]
current = 1
m = m%((1+n)*n//2)
while True:
    if m>=current:
        m -= current
        current = current%n+1
    else:
        break
print(m)
