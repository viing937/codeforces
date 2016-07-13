n, h = map(int, input().split())
a = list(map(int, input().split()))

width = len([ai for ai in a if ai > h])*2 + len([ai for ai in a if ai <= h])
print(width)
