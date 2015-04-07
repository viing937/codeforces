# coding: utf-8
def union(s,n):
    i = 0
    while i < n:
        j = i+1
        while j < n:
            if s[i]&s[j]:
                s[i] = s[i]|s[j]
                del(s[j])
                n -= 1
            else:
                j += 1
        i += 1
    return s, n
n, m = [int(i) for i in input().split()]
languages = []
ans = 0
for i in range(n):
    tmp = set([int(j) for j in input().split()[1:]])
    if tmp:
        languages.append(tmp)
    else:
        n -= 1
        ans += 1
languages, n = union(languages,n)
languages, n = union(languages,n)
if languages:
    ans += n-1
print(ans)
