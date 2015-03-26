# coding: utf-8
s = input()
t = input()
pos = 0
for i in t:
    if i == s[pos]:
        pos += 1
print(pos+1)
