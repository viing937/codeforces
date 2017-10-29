n, v = map(int, input().split(" "))
a, b = [], []
for i in range(n):
    t, p = map(int, input().split(" "))
    if t == 1:
        a.append([p, i+1])
    else:
        b.append([p, i+1])
a.sort(reverse = True)
b.sort(reverse = True)
i, j = 0, 0
while v > 0 and i+j < n:
    if v == 1:
        if i < len(a):
            v -= 1
            i += 1
        if v == 0 and i > 1 and j < len(b) and a[i-1][0] + a[i-2][0] < b[j][0]:
            i -= 2
            j += 1
        if v == 1 and i > 0 and j < len(b) and a[i-1][0] < b[j][0]:
            v -= 1
            i -= 1
            j += 1
        break
    else:
        if i < len(a) and j < len(b):
            if a[i][0] * 2 > b[j][0]:
                v -= 1
                i += 1
            else:
                v -= 2
                j += 1
        elif i < len(a):
            v -= 1
            i += 1
        else:
            v -= 2
            j += 1
a, b = a[:i], b[:j]
capacity = sum([t[0] for t in a]) + sum([t[0] for t in b])
s = [t[1] for t in a] + [t[1] for t in b]
print(capacity)
print(" ".join(map(str, s)))
