# coding: utf-8
a = input()
pos = a.find('0')
if pos==-1:
    print(a[:-1])
else:
    print(a[:pos]+a[pos+1:])
