# coding: utf-8
import re
def trans_1(num):
    if num == 0:
        return '0'
    else:
        return trans_1((num-1)//26).lstrip('0')+'ABCDEFGHIJKLMNOPQRSTUVWXYZ'[num%26-1]
def trans_2(string):
    num = 0
    for ch in string:
        num = num*26+ord(ch)-ord('A')+1
    return num
r = re.compile('R[0-9]+C[0-9]+')
n = int(input())
for i in range(n):
    s = input()
    if r.match(s):
        temp = re.findall('[0-9]+',s)
        print(trans_1(int(temp[1])),temp[0],sep='')
    else:
        print('R',''.join(list(filter(str.isdigit,s))),'C',trans_2(''.join(list(filter(str.isalpha,s)))),sep='')
