# coding: utf-8
n = int(input())
s = input()
ans = 0
key = {}
for i in range(26):
    key[chr(ord('a')+i)] = 0
for i in range(2*n-2):
    if s[i].islower():
        key[s[i]] += 1
    else:
        if key[s[i].lower()] <= 0:
            ans += 1
        else:
            key[s[i].lower()] -= 1
print(ans)
