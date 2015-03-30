# coding: utf-8
n = int(input())
if n>=4 and (n-4)%2==0:
    print('YES')    
    print('1 * 2 = 2')
    print('2 * 3 = 6')
    print('6 * 4 = 24')
    tmp = 4
    for i in range((n-4)//2):
        print(tmp+2,'-',tmp+1,'=',1)
        print('24 * 1 = 24')
        tmp += 2
elif n>=5 and (n-5)%2==0:
    print('YES')
    print('5 - 3 = 2')
    print('2 * 4 = 8')
    print('1 + 2 = 3')
    print('3 * 8 = 24')
    tmp = 5
    for i in range((n-5)//2):
        print(tmp+2,'-',tmp+1,'=',1)
        print('24 * 1 = 24')
        tmp += 2
else:
    print('NO')
