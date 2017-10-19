import math
EPSILON = 0.0001

def radians(x1, y1, x2, y2):
    product = x1*x2 + y1*y2
    norm1 = (x1*x1+y1*y1) ** 0.5
    norm2 = (x2*x2+y2*y2) ** 0.5
    cosVal = max(-1, min(1, product/norm1/norm2))
    return math.acos(cosVal)

x1, y1 = map(float, input().split(" "))
x2, y2 = map(float, input().split(" "))
x3, y3 = map(float, input().split(" "))

a, b, c, d = x1-x2, y1-y2, x1-x3, y1-y3
e = ((x1*x1-x2*x2) - (y2*y2-y1*y1)) / 2
f = ((x1*x1-x3*x3) - (y3*y3-y1*y1)) / 2
ox = -(d*e-b*f)/(b*c-a*d)
oy = -(a*f-c*e)/(b*c-a*d)

alpha1 = radians(x1-ox, y1-oy, x2-ox, y2-oy)
alpha2 = radians(x1-ox, y1-oy, x3-ox, y3-oy)
for i in range(3, 101):
    unit = 2*math.pi/i
    if abs(alpha1/unit - round(alpha1/unit)) > EPSILON:
        continue
    if abs(alpha2/unit - round(alpha2/unit)) > EPSILON:
        continue
    radius = ((x1-ox)**2 + (y1-oy)**2) ** 0.5
    area = 0.5 * radius * radius * math.sin(unit) * i;
    print(area)
    exit()
