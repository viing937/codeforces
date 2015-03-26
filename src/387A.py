# coding: utf-8
s = [int(i) for i in input().split(':')]
stime = s[0]*60+s[1]+24*60
t = [int(i) for i in input().split(':')]
ttime = t[0]*60+t[1]
ptime = stime-ttime
print('%02d:%02d' % (ptime//60%24,ptime%60) )
