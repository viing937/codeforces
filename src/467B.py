# coding: utf-8
def trans_to_binary(num):
    if num == 0:
        return '0'
    else:
        return trans_to_binary(num//2).lstrip('0')+'01'[num%2]
n, m, k = [int(i) for i in input().split()]
li = []
for i in range(m):
    temp = trans_to_binary(int(input()))
    temp = '0'*(n-len(temp))+temp
    li.append(temp)
fedor = trans_to_binary(int(input()))
fedor = '0'*(n-len(fedor))+fedor
ans = 0
for s in li:
    cnt = 0
    for i in range(n):
        if fedor[i] != s[i]:
            cnt += 1
    if cnt <= k:
        ans += 1
print(ans)
