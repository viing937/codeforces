# coding: utf-8
n = int(input())
li = []
for i in range(n):
    li.append([int(i) for i in input().split()])
li.sort(reverse=True)
last = li.pop()[-1]
while li:
    if li[-1][-1]>=last:
        last = li.pop()[-1]
    else:
        last = li.pop()[0]
print(last)
