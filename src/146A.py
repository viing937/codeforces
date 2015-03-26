# coding: utf-8
def check(num):
    for ch in num:
        if ch!=4 and ch!=7:
            return False
    if sum(num[:len(num)//2]) != sum(num[len(num)//2:]):
        return False
    return True
n = input()
if check([int(i) for i in input()]):
    print('YES')
else:
    print('NO')
