n = int(input())

f, m = [0]*368, [0]*368
for i in range(n):
    s, a, b = input().split()
    if s == 'F':
        f[int(a)] += 1
        f[int(b)+1] -= 1
    elif s == 'M':
        m[int(a)] += 1
        m[int(b)+1] -= 1

for i in range(1, len(f)):
    f[i] += f[i-1]
    m[i] += m[i-1]

print(max([min(f[i], m[i])*2 for i in range(1, 367)]))
