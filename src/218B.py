n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
max_ans = 0
min_ans = 0
maxli = list(a)
minli = list(a)
while n > 0:
    n -= 1
    max_index = max(maxli)
    max_ans += max_index
    max_index = maxli.index(max_index)
    if maxli[max_index] == 1:
        del(maxli[max_index])
    else:
        maxli[max_index] -= 1
    min_index = min(minli)
    min_ans += min_index
    min_index = minli.index(min_index)
    if minli[min_index] == 1:
        del(minli[min_index])
    else:
        minli[min_index] -= 1
print(max_ans, min_ans)
