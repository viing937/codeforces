from collections import Counter
n = int(input())
c = Counter(input().split())
cnt = n//3
if c['1']==cnt and c['2']+c['3']==cnt and c['4']+c['6']==cnt and c['2']>=c['4']:
    for i in range(c['4']):
        print('1 2 4')
    for i in range(c['2']-c['4']):
        print('1 2 6')
    for i in range(c['1']-c['2']):
        print('1 3 6')
else:
    print(-1)
