# coding: utf-8
s = list(input())
t = input()
cf = 1
for i in range(len(s)-1,-1,-1):
    if cf:
        if s[i] == 'z':
            s[i] = 'a'
        else:
            s[i] = chr(ord(s[i])+1)
            cf = 0
s = ''.join(s)
if s < t:
    print(s)
else:
    print('No such string')
