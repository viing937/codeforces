# coding: utf-8
n = int(input())
li = [i for i in input().split()]
li1 = []
li2 = []
li3 = []
for i in range(1,n+1):
    if li[i-1] == '1':
        li1.append(i)
    if li[i-1] == '2':
        li2.append(i)
    if li[i-1] == '3':
        li3.append(i)
cnt = min(len(li1),len(li2),len(li3))
print(cnt)
for i in range(cnt):
    print(li1[i],li2[i],li3[i])
