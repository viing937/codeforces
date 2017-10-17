s, v1, v2, t1, t2 = map(int, input().split(' '))
f1 = v1 * s + 2 * t1
f2 = v2 * s + 2 * t2
if f1 < f2:
    print("First")
elif f1 > f2:
    print("Second")
else:
    print("Friendship")
