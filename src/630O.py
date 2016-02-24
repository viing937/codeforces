import math

px, py, vx, vy, a, b, c, d = map(int, input().split(' '))

l = math.sqrt(vx*vx+vy*vy)

print(px+b/l*vx, py+b/l*vy)
print(px-a/2/l*vy, py+a/2/l*vx)
print(px-c/2/l*vy, py+c/2/l*vx)
print(px-c/2/l*vy-d/l*vx, py+c/2/l*vx-d/l*vy)
print(px+c/2/l*vy-d/l*vx, py-c/2/l*vx-d/l*vy)
print(px+c/2/l*vy, py-c/2/l*vx)
print(px+a/2/l*vy, py-a/2/l*vx)
