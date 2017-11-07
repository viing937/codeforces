n = int(input())
s = input()
c = len(set(s))
if n > 26:
    print(-1)
else:
    print(n-c)
