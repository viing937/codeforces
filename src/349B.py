v = int(input())
a = [int(i) for i in input().split()]
ans = (v//min(a))*[9-a[::-1].index(min(a))]
v %= min(a)
for i in range(len(ans)):
    for j in range(8,-1,-1):
        if j+1 > ans[i] and a[j]-a[ans[i]-1] <= v:
            v -= a[j]-a[ans[i]-1]
            ans[i] = j+1
    if v <= 0:
        break
if ans:
    print("".join([str(i) for i in ans]))
else:
    print(-1)
