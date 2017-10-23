n, m, k = map(int, input().split(" "))
a = list(map(int, input().split(" ")))
for i in range(1, n+1):
    if (m-i-1 >= 0 and a[m-i-1] != 0 and k >= a[m-i-1]) or \
       (m+i-1 < n and a[m+i-1] != 0 and k >= a[m+i-1]):
        print(i*10)
        exit()
