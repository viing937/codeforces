# coding: utf-8
l1 = 'qwertyuiop'
l2 = 'asdfghjkl;'
l3 = 'zxcvbnm,./'
m = {}
flag = input()
s = input()
if flag == 'R':
    for i in range(1,len(l1)):
        m[l1[i]] = l1[i-1]
    for i in range(1,len(l2)):
        m[l2[i]] = l2[i-1]
    for i in range(1,len(l3)):
        m[l3[i]] = l3[i-1]
else:
    for i in range(len(l1)-1):
        m[l1[i]] = l1[i+1]
    for i in range(len(l2)-1):
        m[l2[i]] = l2[i+1]
    for i in range(len(l3)-1):
        m[l3[i]] = l3[i+1]
for ch in s:
    print(m[ch], end='')
print('')
