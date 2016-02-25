import math

l3, l4, l5 = map(int, input().split(' '))

print(math.sqrt(2)*l3*l3*l3/12 + math.sqrt(2)*l4*l4*l4/6 + (5+math.sqrt(5))*l5*l5*l5/24)
