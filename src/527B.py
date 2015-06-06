n = int(input())
s = input()
t = input()
diff = {}
dis = 0
for i in range(len(s)):
    if s[i]!=t[i]:
        dis += 1
        diff[s[i]+t[i]] = i+1
for d in diff.keys():
    if diff.get(d[::-1],0) > 0:
        print(dis-2)
        print(diff[d], diff[d[::-1]])
        exit()
for d in diff.keys():
    for dd in diff.keys():
        if d[0]==dd[1] or d[1]==dd[0]:
            print(dis-1)
            print(diff[d], diff[dd])
            exit()
print(dis)
print(-1, -1)
