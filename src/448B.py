# coding: utf-8
from collections import Counter
s = list(input())
t = list(input())
cs = Counter(s)
ct = Counter(t)
if cs == ct:
    print('array')
    exit()
if ct - cs:
    print('need tree')
    exit()
index = 0
length = len(s)
for ch in t:
    while index < length and s[index] != ch:
        del(s[index])
        length -= 1
    index += 1
s = s[:index]
if s == t:
    print('automaton')
else:
    print('both')
