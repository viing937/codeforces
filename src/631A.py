from functools import reduce

n = int(input())
a = map(int, input().split(' '))
b = map(int, input().split(' '))

print(reduce(lambda x,y: x|y, a)+reduce(lambda x,y: x|y, b))
