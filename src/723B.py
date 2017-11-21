n = int(input())
s = input() + '_'
a, b = 0, 0
l, f = 0, False
for c in s:
    if c == '(':
        a = max(a, l)
        l, f = 0, True
    elif c == ')':
        b += 1 if l > 0 else 0
        l, f = 0, False
    elif c == '_':
        if f:
            b += 1 if l > 0 else 0
        else:
            a = max(a, l)
        l = 0
    else:
        l += 1
print(a, b)
