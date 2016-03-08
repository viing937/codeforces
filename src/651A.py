a1, a2 = sorted(map(int, input().split(' ')))

if (a2-a1)%3:
    print(max(0, a1+a2-2))
else:
    print(max(0, a1+a2-3))
