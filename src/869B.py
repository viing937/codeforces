a, b = map(int, input().split(' '))
r = 1
for i in range(a+1, b+1):
    if i % 10 == 0:
        r = 0
        break
    r = (r * (i%10)) % 10
print(r)
