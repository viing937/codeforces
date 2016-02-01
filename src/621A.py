n = int(input())
even, odd = [], []
for num in map(int, input().split(' ')):
    if num%2:
        odd.append(num)
    else:
        even.append(num)
ans = sum(even)+sum(odd)
if len(odd)%2:
    ans = ans-min(odd)
print(ans)
