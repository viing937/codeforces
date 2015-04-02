# coding: utf-8
s = input()
ans = 0
while s.find('bear') != -1:
    index = s.find('bear')
    ans += (index+1)*(len(s)-index-4+1)
    s = s[index+1:]
print(ans)
