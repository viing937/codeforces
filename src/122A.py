# coding: utf-8
n = int(input())
def islucky(a):
    a = str(a)
    for ch in a:
        if ch!='4' and ch!='7':
            return False
    return True
for i in range(1,n+1):
    if islucky(i) and n%i==0:
        print('YES')
        break
else:
    print('NO')
    
