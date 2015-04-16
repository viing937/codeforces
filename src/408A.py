n = int(input())
k = [int(i) for i in input().split()]
ans = []
for i in range(n):
    m = [int(j) for j in input().split()]
    ans.append(sum(m)*5+k[i]*15)
print(min(ans))
