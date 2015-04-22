from itertools import permutations
n, m = [int(i) for i in input().split()]
maxsum = -1
ans = []
for per in permutations(range(1,n+1),n):
    thissum = 0
    for i in range(n):
        for j in range(i,n):
            thissum += min(per[i:j+1])
    if thissum > maxsum:
        maxsum = thissum
        ans = [per]
    elif thissum == maxsum:
        ans.append(per)
print(' '.join([str(i) for i in ans[m-1]]))
