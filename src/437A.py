# coding: utf-8
choice = [input() for i in range(4)]
choice = sorted([[len(choice[i][2:]),choice[i][2:],choice[i][0]] for i in range(4)])
ans = []
if choice[0][0]*2<=choice[1][0] and choice[0][0]*2<=choice[2][0] and choice[0][0]*2<=choice[3][0]:
        ans.append(choice[0][2])
if choice[3][0]>=choice[0][0]*2 and choice[3][0]>=choice[1][0]*2 and choice[3][0]>=choice[2][0]*2:
        ans.append(choice[3][2])
if len(ans)==1:
    print(ans[0])
else:
    print('C')
