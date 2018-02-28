n = int(input())
r = ['o'] * n
i, j = 0, 1
while j-1 < n:
    r[j-1] = 'O'
    i, j = j, i+j
print(''.join(r))
