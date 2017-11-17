n = int(input())
pos, result = 0, True
for i in range(n):
    t, dire = input().split(" ")
    if pos == 0 and dire != "South":
        result = False
    if pos == 20000 and dire != "North":
        result = False
    if dire == "East" or dire == "West":
        continue
    t = int(t)
    if dire == "South":
        pos = pos + t
    else:
        pos = pos - t
    if pos < 0 or pos > 20000:
        result = False
if pos == 0 and result:
    print("YES")
else:
    print("NO")
