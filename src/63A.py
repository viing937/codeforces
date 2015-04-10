# coding: utf-8
n = int(input())
d = {'rat':0, 'woman':1, 'child':1, 'man':2, 'captain':3}
people = []
for i in range(n):
    tmp = input().split()
    people.append([d[tmp[1]], i, tmp[0]])
people.sort()
for i in people:
    print(i[2])
