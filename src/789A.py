n, k = map(int, input().split())
w = list(map(int, input().split()))
r = sum(map(lambda x: (x+k-1)//k, w))
print((r+1)//2)
