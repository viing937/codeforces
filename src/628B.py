s = input()

ans = 0
for i in range(len(s)):
    if int(s[i])%4 == 0:
        ans += 1
    if i > 0 and (int(s[i-1])*10+int(s[i]))%4 == 0:
        ans += i
print(ans)
