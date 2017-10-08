n = input()
a = [int(i) for i in input().split(' ')]
maxVal = max(a)
result = sum(map(lambda x: maxVal-x, a))
print(result)
