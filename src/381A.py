# coding: utf-8
n = int(input())
li = [int(i) for i in input().split()]
sereja = 0
dima = 0
while li:
    if li[0] >= li[-1]:
        sereja += li[0]
        del(li[0])
    else:
        sereja += li[-1]
        del(li[-1])
    if li:
        if li[0] >= li[-1]:
            dima += li[0]
            del(li[0])
        else:
            dima += li[-1]
            del(li[-1])
print(sereja,dima)
