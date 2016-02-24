import math

a, b, c = map(int, input().split(' '))
if a < 0:
    a, b, c = -a, -b, -c

delta = b*b-4*a*c

print((-b+math.sqrt(delta))/2/a)
print((-b-math.sqrt(delta))/2/a)
