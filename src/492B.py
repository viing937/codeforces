# coding: utf-8
n, l = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
a.sort()
li = [a[0]-0,l-a[-1]]
for i in range(n-1):
    li.append((a[i+1]-a[i])/2)
print(max(li))
