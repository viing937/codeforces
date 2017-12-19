layout1, layout2 = input(), input()
m = dict(zip(layout1 + layout1.upper(), layout2 + layout2.upper()))
s = input()
result = [m[ch] if ch.isalpha() else ch for ch in s]
print(''.join(result))
