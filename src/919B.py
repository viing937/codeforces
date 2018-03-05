k = int(input())
s = []
r = [[], ['1'], ['2'], ['3'], ['4'], ['5'], ['6'], ['7'], ['8'], ['9'], []]
while len(s) < k:
    for i in range(10, 0, -1):
        t = []
        for j in range(0, i):
            suffix = str(j)
            t += list(map(lambda x: x+suffix, r[i-j]))
        r[i] = t
    s += r[10]
s = sorted(map(int, s))
print(s[k-1])
