n = int(input())
a = sum(map(int, input().split(' ')))
b = sum(sorted(map(int, input().split(' ')))[-2:])
if a <= b:
    print('YES')
else:
    print('NO')
