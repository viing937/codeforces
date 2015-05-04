n = int(input())
a = list(input())
ans = a
for i in range(0,10):
    for j in range(0,n):
        if a < ans:
            ans = a
        a = a[1:] + [a[0]]
    for j in range(0,n):
        a[j] = str((int(a[j])+1)%10)
print("".join(ans))
