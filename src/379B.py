# coding: utf-8
n = int(input())
a = [int(i) for i in input().split()] + [0]
ans = []
current = 0
while current<n:
    if a[current]>0 and a[current+1]>0:
        ans.append('PRPL')
        a[current] -= 1
        a[current+1] -= 1
    elif a[current]>0:
        if current==n-1:
            ans.append('PLR')
        else:
            ans.append('PRL')
        a[current] -= 1
    else:
        if current!=n-1:
            ans.append('R')
        current += 1
print(''.join(ans))
