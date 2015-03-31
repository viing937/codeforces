# coding: utf-8
def check(a,b,s,ans):
    for j in range(b):
        if [s[k] for k in range(12) if k%b==j].count('X')==a:
            ans.append('%dx%d'%(a,b))
            return ans
    return ans
t = int(input())
for i in range(t):
    ans = []
    s = input()
    ans = check(1,12,s,ans)
    ans = check(2,6,s,ans)
    ans = check(3,4,s,ans)
    ans = check(4,3,s,ans)
    ans = check(6,2,s,ans)
    ans = check(12,1,s,ans)
    if ans:
        print(len(ans),' '.join(ans))
    else:
        print(0)
