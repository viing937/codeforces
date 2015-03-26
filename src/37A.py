# coding: utf-8
n = int(input())
li = {}
for i in input().split():
    if i in li.keys():
        li[i] += 1
    else:
        li[i] = 1
print(max(li.values()),len(li.keys()))
