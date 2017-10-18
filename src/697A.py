t, s, x = map(int, input().split(" "))
if x == t:
    print("YES")
elif x-t-s >= 0 and (x-t-s)%s < 2:
    print("YES")
else:
    print("NO")
