from collections import Counter

s = input()
m = Counter(s)
result, target = 6666666, Counter("Bulbasaur")
for ch in target.keys():
    result = min(result, m[ch]//target[ch])
print(result)
