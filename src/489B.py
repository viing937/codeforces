# coding: utf-8
n = int(input())
a = [int(i) for i in input().split()]
a.sort()
m = int(input())
b = [int(i) for i in input().split()]
b.sort()
ans = 0
while a and b:
    if abs(a[-1]-b[-1])<=1:
        ans += 1
        a.pop()
        b.pop()
    elif a[-1]>b[-1]:
        a.pop()
    else:
        b.pop()
print(ans)
