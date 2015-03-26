# coding: utf-8
a = int(input())
b = int(input())
c = int(input())
li = []
li.append((a+b)+c)
li.append((a+b)*c)
li.append((a*b)+c)
li.append((a*b)*c)
li.append(a+(b+c))
li.append(a+(b*c))
li.append(a*(b+c))
li.append(a*(b*c))
print(max(li))
