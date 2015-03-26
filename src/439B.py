# coding: utf-8
n, x = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]
c.sort(reverse=True)
ans = 0
while c:
    ans += x*c.pop()
    if x>1:
        x -= 1
    else:
        ans += sum(c)
        break
print(ans)
