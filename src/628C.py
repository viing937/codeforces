n, k = map(int, input().split(' '))
s = list(input())
if k <= n:
    for i in range(k):
        s[i] = chr(ord(s[i])-1) if s[i]!='a' else chr(ord(s[i])+1)
    print(''.join(s))
else:
    acc = 0
    for i in range(n):
        if ord(s[i]) <= ord('m'):
            if k - acc <= ord('z') - ord(s[i]):
                s[i] = chr(ord(s[i])+k-acc)
                acc = k
            else:
                acc += ord('z') - ord(s[i])
                s[i] = 'z'
        else:
            if k - acc <= ord(s[i]) - ord('a'):
                s[i] = chr(ord(s[i])-k+acc)
                acc = k
            else:
                acc += ord(s[i]) - ord('a')
                s[i] = 'a'
    if acc < k:
        print(-1)
    else:
        print(''.join(s))
