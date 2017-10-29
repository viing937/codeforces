n, k = map(int, input().split(" "))
s = input()
G, T = s.find("G"), s.find("T")
G, T = min(G, T), max(G, T)
if (T-G) % k:
    print("NO")
    exit()
for step in range(G+k, T, k):
    if s[step] == "#":
        print("NO")
        break
else:
    print("YES")
