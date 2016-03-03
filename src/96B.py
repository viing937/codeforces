from itertools import combinations

n = input()
t = len(n)

if t%2:
    print('4'*(t//2+1)+'7'*(t//2+1))
else:
    for com in combinations(range(t), t//2):
        num = ['7']*t
        for s in com:
            num[s] = '4'
        num = int(''.join(num))
        if num >= int(n):
            print(num)
            exit()
    print('4'*(t//2+1)+'7'*(t//2+1))
