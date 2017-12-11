from collections import Counter
n = int(input())
a = Counter([int(input()) for i in range(n)])
if len(a) != 2 or len(set(a.values())) != 1:
    print('NO')
else:
    print('YES')
    print(' '.join(map(str, a.keys())))
