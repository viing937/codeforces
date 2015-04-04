# coding: utf-8
from collections import Counter
lettters = [chr(ord('A')+i) for i in range(26)] + [chr(ord('a')+i) for i in range(26)]
s = Counter(input())
t = Counter(input())
yay = 0
whoops = 0

tmp = Counter()
for lettter in lettters:
    tmp[lettter] = min(s[lettter],t[lettter])
s -= tmp
t -= tmp
yay += sum(tmp.values())

tmp = Counter()
for lettter in lettters[:26]:
    tmp[lettter] = min(s[lettter.lower()],t[lettter])
    tmp[lettter.lower()] = min(s[lettter.lower()],t[lettter])
s -= tmp
t -= tmp
whoops += sum(tmp.values())//2

tmp = Counter()
for lettter in lettters[26:]:
    tmp[lettter] = min(s[lettter.upper()],t[lettter])
    tmp[lettter.upper()] = min(s[lettter.upper()],t[lettter])
s -= tmp
t -= tmp
whoops += sum(tmp.values())//2

print(yay,whoops)
