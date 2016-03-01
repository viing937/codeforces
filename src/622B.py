hh, mm = map(int, input().split(':'))
a = int(input())

print(('%02d'%((hh+(mm+a)//60)%24)) + ':' + ('%02d'%((mm+a)%60)))
