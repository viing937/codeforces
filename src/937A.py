n = int(input())
a = list(map(int, input().split()))
r = len(set(filter(lambda x: x>0, a)))
print(r)
