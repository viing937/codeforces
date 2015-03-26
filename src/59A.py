# coding: utf-8
up = 0
low = 0
s = input()
for ch in s:
    if ch.isupper():
        up += 1
    else:
        low += 1
if low >= up:
    print(s.lower())
else:
    print(s.upper())
