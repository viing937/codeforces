n, m = map(int, input().split(' '))

x = max(n*2, m*3)
while x//2+x//3-x//6 < m+n:
    x += 1

print(x)
