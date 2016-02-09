n = int(input())
a = int(input())
b = int(input())
c = int(input())

if n < a and n < b:
    cnt = 0
elif a <= b-c or n < b:
    cnt = n//a
else:
    rem = b+(n-b)%(b-c)
    cnt = (n-b)//(b-c) + max(rem//a, 1+(rem-b+c)//a)

print(cnt)
