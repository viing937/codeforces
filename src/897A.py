n, m = map(int, input().split(" "))
s = input()
for _ in range(m):
    l, r, c1, c2 = input().split(" ")
    l, r = int(l), int(r)
    s = s[:l-1] + c2.join(s[l-1:r].split(c1)) + s[r:]
print(s)
