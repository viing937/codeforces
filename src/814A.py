n, k = map(int, input().split(" "))
a = list(map(int, input().split(" ")))
b = list(map(int, input().split(" ")))

if k > 1:
    print("Yes")
    exit()

a[a.index(0)] = b[0]
for i in range(1, n):
    if a[i-1] != 0 and a[i] != 0 and a[i-1] > a[i]:
        print("Yes")
        break
else:
    print("No")
