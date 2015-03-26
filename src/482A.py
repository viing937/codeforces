# coding: utf-8
n, k = [int(i) for i in input().split()]
ans = ['1']
for i in range(k):
    if i%2==0:
        ans.append(str(int(ans[-1])+(k-i)))
    else:
        ans.append(str(int(ans[-1])-(k-i)))
ans += [str(i) for i in range(k+2,n+1)]
print(' '.join(ans))
