n = int(input())

m = {}
for i in range(n):
    s = input()
    m[s] = (-i, s)
m = [t[1] for t in sorted(m.values())]

print('\n'.join(m))
