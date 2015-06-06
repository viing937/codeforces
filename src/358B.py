n = int(input())
s = []
for i in range(n):
    s.append(input())
s = "<3".join([""]+s+[""])
text = input()
i = 0
for ch in s:
    while i<len(text) and text[i]!=ch:
        i += 1
    if i >= len(text):
        print("no")
        exit()
    i += 1
print("yes")
