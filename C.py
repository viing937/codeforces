from collections import Counter
n = int(input())
a = [int(i) for i in input().split()]
if n == 1:
    print(0)
    exit()
c = Counter(a)
pow_2 = set([pow(2, i) for i in range(32)])
min_L = min(a)
flag = False
for aa in c.keys():
    if aa%min_L != 0 or aa//min_L not in pow_2:
        flag = True
        break
ans = 0
if flag:
    for aa in c.keys():
        aaa = aa
        while aaa > 1:
            ans += c[aa]
            aaa //= 2
else:
    if len(a) == 2:
        bal = a[0]
    else:
        sorted_a = sorted(a)
        bal = sorted_a[n//2]
    for aa in c.keys():
        if bal > aa:
            t = bal // aa
        elif bal < aa:
            t = aa // bal
        else:
            continue
        while t != 1:
            t //= 2
            ans += c[aa]
print(ans)
