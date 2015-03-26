# coding: utf-8
a, b, c = [int(i) for i in input().split()]
ans = set()
for i in range(1,10):
    for j in range(1,9*i+1):
        x = b*pow(j,a)+c
        if x>0 and len(str(x))==i and sum([int(k) for k in str(x)])==j:
            ans.add(x)
print(len(ans))
if ans:
    print(' '.join([str(i) for i in sorted(list(ans))]))
