# coding: utf-8
n = int(input())
li = [int(i) for i in input().split()]
for i in range(n):
    li[i] = [li[i],i+1]
li.sort()
if n == 1:
    print(1)
elif li[0][0] == li[1][0]:
    print('Still Rozdil')
else:
    print(li[0][1])
