s = input()
t = set(['a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9'])
print(sum(map(lambda x: 1 if x in t else 0, s)))
