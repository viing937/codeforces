import math

def calCircle(x1, y1, r1, x2, y2, r2):
    inner = (x1 + r1/(r1+r2) * (x2-x1), y1 + r1/(r1+r2) * (y2-y1))
    outer = ((r2*x1-r1*x2) / (r2-r1), (r2*y1-r1*y2) / (r2-r1))
    centre = ((inner[0]+outer[0])/2, (inner[1]+outer[1])/2)
    radius = ((inner[0]-centre[0])**2 + (inner[1]-centre[1])**2) ** 0.5
    return centre, radius

x1, y1, r1 = map(float, input().split(" "))
x2, y2, r2 = map(float, input().split(" "))
x3, y3, r3 = map(float, input().split(" "))

if r1 == r2 and r1 == r3:
    a, b, c, d = x1-x2, y1-y2, x1-x3, y1-y3
    e = ((x1*x1-x2*x2) + (y1*y1-y2*y2)) / 2
    f = ((x1*x1-x3*x3) + (y1*y1-y3*y3)) / 2
    x = -(d*e-b*f)/(b*c-a*d)
    y = -(a*f-c*e)/(b*c-a*d)
elif r1 == r2:
    a, b, c = x1-x2, y1-y2, ((x1*x1-x2*x2) + (y1*y1-y2*y2)) / 2
    centre, radius = calCircle(x1, y1, r1, x3, y3, r3)
    p = 1+(a*a)/(b*b)
    q = 2*(centre[1]-c/b)*a/b-2*centre[0]
    r = centre[0]**2+(centre[1]-c/b)**2-radius*radius
    delta = q*q - 4*p*r
    px1, px2 = (-q+math.sqrt(delta))/(2*p), (-q-math.sqrt(delta))/(2*p)
    py1, py2 = (c-a*px1)/b, (c-a*px2)/b
    norm1 = ((px1-x1)**2 + (py1-y1)**2) ** 0.5
    norm2 = ((px2-x1)**2 + (py2-y1)**2) ** 0.5
    if r1 / norm1 > r1 / norm2:
        x, y = px1, py1
    else:
        x, y = px2, py2
elif r1 == r3:
    a, b, c = x1-x3, y1-y3, ((x1*x1-x3*x3) + (y1*y1-y3*y3)) / 2
    centre, radius = calCircle(x1, y1, r1, x2, y2, r2)
    p = 1+(a*a)/(b*b)
    q = 2*(centre[1]-c/b)*a/b-2*centre[0]
    r = centre[0]**2+(centre[1]-c/b)**2-radius*radius
    delta = q*q - 4*p*r
    px1, px2 = (-q+math.sqrt(delta))/(2*p), (-q-math.sqrt(delta))/(2*p)
    py1, py2 = (c-a*px1)/b, (c-a*px2)/b
    norm1 = ((px1-x1)**2 + (py1-y1)**2) ** 0.5
    norm2 = ((px2-x1)**2 + (py2-y1)**2) ** 0.5
    if r1 / norm1 > r1 / norm2:
        x, y = px1, py1
    else:
        x, y = px2, py2
else:
    centre1, radius1 = calCircle(x1, y1, r1, x2, y2, r2)
    centre2, radius2 = calCircle(x1, y1, r1, x3, y3, r3)
    d = math.sqrt((centre1[0]-centre2[0])**2 + (centre1[1]-centre2[1])**2)
    l = (radius1**2-radius2**2+d**2) / (2*d)
    if radius1**2-l**2 < 0:
        exit()
    h = math.sqrt(radius1**2-l**2)
    px1 = l/d*(centre2[0]-centre1[0]) + h/d*(centre2[1]-centre1[1]) + centre1[0]
    px2 = l/d*(centre2[0]-centre1[0]) - h/d*(centre2[1]-centre1[1]) + centre1[0]
    py1 = l/d*(centre2[1]-centre1[1]) - h/d*(centre2[0]-centre1[0]) + centre1[1]
    py2 = l/d*(centre2[1]-centre1[1]) + h/d*(centre2[0]-centre1[0]) + centre1[1]
    norm1 = ((px1-x1)**2 + (py1-y1)**2) ** 0.5
    norm2 = ((px2-x1)**2 + (py2-y1)**2) ** 0.5
    if r1 / norm1 > r1 / norm2:
        x, y = px1, py1
    else:
        x, y = px2, py2
print(x, y)
