n = int(input())
a = sorted(set(map(int, input().split())))
if len(a) > 3:
    print('NO')
elif len(a) <= 2:
    print('YES')
elif len(a) == 3:
    print('YES' if a[0]+a[2]==2*a[1] else 'NO')
