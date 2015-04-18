p = [1]
for i in range(32):
    p.append(p[-1]*2)
n = input()
length = len(n)
ans = 0
for i in range(1,length):
    ans += p[i]
for i in range(length-1):
    if n[i] == '7':
        ans += p[length-i-1]
if n[-1] == '7':
    ans += 2
else:
    ans += 1
print(ans)
