import math

n, r = map(int, input().split(' '))

alpha = math.pi/n/2
beta = math.pi/n
gamma = math.pi-alpha-beta

print(r*r*math.sin(alpha)*math.sin(beta)/math.sin(gamma)*n)
