n, p = map(int, input().split(' '))
s = [input() for i in range(n)][::-1]

apple = 0
money = 0
for line in s:
    if line == 'halfplus':
        apple = apple*2+1
    elif line == 'half':
        apple = apple*2
    money += p//2*apple

print(money)
