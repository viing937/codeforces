from collections import Counter
n = Counter(input())
m = Counter(input())
ans = 0
for i in range(0,26):
    if m[chr(ord('a')+i)] > 0 and n[chr(ord('a')+i)] == 0:
        print(-1)
        exit()
    ans += min(m[chr(ord('a')+i)], n[chr(ord('a')+i)])
print(ans)
