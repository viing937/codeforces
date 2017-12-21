def decode(s):
    n = len(s)
    if n == 0:
        return ""
    l, r = "", ""
    for i in range(n%2, n, 2):
        l = s[i] + l
        r = r + s[i+1]
    return l + (s[0] if n%2 else "") + r

n = int(input())
s = input()
r = decode(s)
print(r)
