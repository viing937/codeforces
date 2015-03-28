# coding: utf-8
a = input()
b = input()
c = int(''.join([ch for ch in str(int(a)+int(b)) if ch!='0']))
a = int(''.join([ch for ch in a if ch!='0']))
b = int(''.join([ch for ch in b if ch!='0']))
if a+b==c:
    print('YES')
else:
    print('NO')
