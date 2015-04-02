# coding: utf-8
n = int(input())
a = set(input().split())
todel = set()
for i in a:
    if int(i)>n:
        todel.add(i)
    a = a-todel
print(n-len(a))
