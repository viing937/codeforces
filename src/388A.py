# coding: utf-8
n = int(input())
ans = 0
li1 = [int(i) for i in input().split()]
li2 = []
while li1:
    li1.sort()
    n = len(li1)
    i = 0
    while i < n:
        if li1[i] < i:
            li2.append(li1[i])
            del(li1[i])
            n -= 1
        else:
            i += 1
    ans += 1
    li1 = li2
    li2 = []
print(ans)
