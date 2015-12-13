n = int(input())
if n < 3:
    print(-1)
else:
    t = 10**(n-1)
    print(t+210-t%210)
