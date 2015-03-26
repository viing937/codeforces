# coding: utf-8
n = int(input())
li = []
for i in range(n):
    li.append([int(j) for j in input().split()])
li.sort()
l = [i[1] for i in li]
if l != sorted(l):
    print('Happy Alex')
else:
    print('Poor Alex')
    
