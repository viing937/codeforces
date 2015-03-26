n = int(input())
cnt = 5

while n > cnt:
    n -= cnt
    cnt *= 2

ans = n/cnt*5
if ans > 4:
    print('Howard')
elif ans > 3:
    print('Rajesh')
elif ans > 2:
    print('Penny')
elif ans > 1:
    print('Leonard')
else:
    print('Sheldon')
