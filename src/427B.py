# coding: utf-8
n, t, c = [int(i) for i in input().split()]
crime = [1 if int(i) <= t else 0 for i in input().split()]
sta = 0
ans = 0
for i in crime:
    if i == 0:
        sta = 0
    else:
        sta += 1
    if sta>=c:
        ans += 1
print(ans)
