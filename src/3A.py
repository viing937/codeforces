# coding: utf-8
s = input()
t = input()
s = [ord(s[0])-ord('a'),int(s[1])]
t = [ord(t[0])-ord('a'),int(t[1])]
x = t[0]-s[0]
y = t[1]-s[1]
print(max(abs(x),abs(y)))
while x != 0 or y != 0:
    if x > 0:
        print('R',end='')
        x -= 1
    elif x < 0:
        print('L',end='')
        x += 1
    if y > 0:
        print('U',end='')
        y -= 1
    elif y < 0:
        print('D',end='')
        y += 1
    print()
