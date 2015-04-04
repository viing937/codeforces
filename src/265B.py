# coding: utf-8
n = int(input())
heigth = int(input())
ans = heigth+1
for i in range(n-1):
    target = int(input())
    ans += abs(heigth-target)+2
    heigth = target
print(ans)
