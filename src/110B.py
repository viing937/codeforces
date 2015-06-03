n = int(input())
ans = n//4*"abcd"
if n%4==1:
    ans += "a"
elif n%4==2:
    ans += "ab"
elif n%4==3:
    ans += "abc"
print(ans)
