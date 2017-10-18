s = input()
length, diff = len(s), 0
for i in range(length//2):
    diff += 1 if s[i] != s[length-i-1] else 0
if diff == 1:
    print("YES")
elif diff == 0 and length%2:
    print("YES")
else:
    print("NO")
