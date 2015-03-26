# coding: utf-8
def check(li):
    letter_a = li[0][0]
    letter_b = li[0][1]
    n = len(li)
    if letter_a == letter_b:
        return False
    for i in range(n):
        for j in range(n):
            if (i==j or i+j==n-1):
                if li[i][j] != letter_a:
                    return False
            elif li[i][j] != letter_b:
                return False
    return True
n = int(input())
li = []
for i in range(n):
    li.append(input())
if check(li):
    print('YES')
else:
    print('NO')
