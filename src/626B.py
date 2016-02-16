n = int(input())
s = input()
colors = 'BGR'
cnt = [(s.count('B'), 0), (s.count('G'), 1), (s.count('R'), 2)]
cnt.sort()
if cnt[0][0] >= 1 or cnt[1][0] >= 2:
    print(colors)
elif cnt[1][0] == 0:
    print(colors[cnt[2][1]])
elif cnt[1][0] == 1 and cnt[2][0] == 1:
    print(colors[cnt[0][1]])
elif colors[cnt[0][1]] < colors[cnt[1][1]]:
    print(colors[cnt[0][1]]+colors[cnt[1][1]])
else:
    print(colors[cnt[1][1]]+colors[cnt[0][1]])
