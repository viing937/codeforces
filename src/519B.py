# coding: utf-8
from collections import Counter
n = input()
a = Counter([i for i in input().split()])
b = Counter([i for i in input().split()])
c = Counter([i for i in input().split()])
print(''.join(list((a-b).elements())))
print(''.join(list((b-c).elements())))
