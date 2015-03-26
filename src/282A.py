# coding: utf-8
n = int(input())
ans = 0
for i in range(n):
    str = input()
    if '++' in str:
        ans += 1
    elif '--' in str:
        ans -= 1
        
print(ans)
