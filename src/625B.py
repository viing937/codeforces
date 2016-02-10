a = input()
b = input()

ans = 0
while True:
    s = a.find(b)
    if s < 0:
        break
    ans += 1
    a = a[s+len(b):]
print(ans)
