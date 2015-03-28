# coding: utf-8
for i in range(8):
    s = input()
    s1 = set([s[j] for j in range(8) if j%2==0])
    s2 = set([s[j] for j in range(8) if j%2==1])
    if len(s1)!=1 or len(s2)!=1 or s1==s2:
        print('NO')
        break
else:
    print('YES')
