a, b = input().split(" ")
print(a, b)
n = int(input())
for i in range(n):
    x1, x2 = input().split(" ")
    if a == x1:
        a = x2
    else:
        b = x2
    print(a, b)
