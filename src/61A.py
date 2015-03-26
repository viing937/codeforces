# coding: utf-8
a = input()
b = input()
length = len(a)
ans = ''
for i in range(length):
    if int(a[i])+int(b[i])==1:
        ans = ans.join(['', '1'])
    else:
        ans = ans.join(['', '0'])
print(ans)
