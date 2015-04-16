n, k = [int(i) for i in input().split()]
s = set(range(1,n*k+1))
a = [set([int(i)]) for i in input().split()]
for aa in a:
    s -= aa
for i in range(k):
    for j in range(n-len(a[i])):
        a[i].add(s.pop())
    print(' '.join([str(j) for j in list(a[i])]))
