# coding: utf-8
s1 = input()
s2 = input()
s = input()
if sorted(list(s1)+list(s2)) == sorted(list(s)):
    print('YES')
else:
    print('NO')
