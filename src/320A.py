# coding: utf-8
n = [i.strip() for i in input().split('144') if i.strip()!='']
n = [i.strip() for i in ' '.join(n).split('14') if i.strip()!='']
n = [i.strip() for i in ' '.join(n).split('1') if i.strip()!='']
if n:
    print('NO')
else:
    print('YES')
