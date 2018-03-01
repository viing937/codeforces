A, B = map(int, input().split(' '))
x, y, z = map(int, input().split(' '))
print(max(0, 2*x+y-A) + max(0, y+3*z-B))
