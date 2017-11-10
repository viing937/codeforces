n = int(input())
x = list(map(int, input().split(' ')))
table, result = set(), 0
for p in x:
    if p not in table:
        table.add(p)
        result = max(result, len(table))
    else:
        table.remove(p)
print(result)
