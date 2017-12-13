s = input()
m = {}
for i in range(len(s)):
    if s[i] != '!':
        m[i%4] = s[i] 
c = {'R': 0, 'B': 0, 'Y': 0, 'G': 0}
for i in range(len(s)):
    if s[i] == '!':
        c[m[i%4]] += 1
print(c['R'], c['B'], c['Y'], c['G'])
