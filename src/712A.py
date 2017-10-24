n = int(input())
a = list(map(int, input().split(' ')))
b = a[:]
for i in range(len(b)-1):
    b[i] = a[i] + a[i+1]
print(' '.join(map(str, b)))
