name = ["Danil", "Olya", "Slava", "Ann", "Nikita"]
probleamName = input()
c = 0
for n in name:
    c += probleamName.count(n)
print("Yes" if c == 1 else "No")
