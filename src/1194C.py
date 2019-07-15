from collections import Counter


def check(s, t, p):
    p = Counter(p)
    idx = 0
    for ch in t:
        if idx < len(s) and s[idx] == ch:
            idx += 1
        elif ch in p and p[ch] > 0:
            p[ch] -= 1
        else:
            return False
    return idx == len(s)


q = int(input())
for _ in range(q):
    s = input()
    t = input()
    p = input()
    if check(s, t, p):
        print("YES")
    else:
        print("NO")
