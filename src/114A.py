# coding: utf-8
k = int(input())
l = int(input())
tmp = k
ans = 0
while tmp < l:
    tmp *= k
    ans += 1
if pow(k,ans+1)==l:
    print('YES',ans,sep='\n')
else:
    print('NO')
