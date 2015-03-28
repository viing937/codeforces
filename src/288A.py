# coding: utf-8
letter = [chr(ord('a')+i) for i in range(26)]
n, k = [int(i) for i in input().split()]
if k>n or (k==1 and n>1):
    print(-1)
    exit()
if k==1:
    print('a')
    exit()
ans = [letter[i%2] for i in range(n-k+2)]
ans += [letter[2+i] for i in range(k-2)]
print(''.join(ans))
