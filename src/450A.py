# coding: utf-8
n, m = [int(i) for i in input().split()]
li = [(int(i)+m-1)//m for i in input().split()]
li.reverse()
print(n-li.index(max(li)))
