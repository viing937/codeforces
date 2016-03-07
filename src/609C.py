n = int(input())
m = sorted(map(int, input().split(' ')), reverse=True)

s = sum(m)
t, r = s//n, s%n

for i in range(r):
    m[i] -= 1

print(sum(map(lambda a:a-t if a>t else 0, m)))
