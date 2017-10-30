cd = input()
w = 3 if cd[0] != 'a' and cd[0] != 'h' else 2
h = 3 if cd[1] != '1' and cd[1] != '8' else 2
print(w*h-1)
