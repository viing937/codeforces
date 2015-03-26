# coding: utf-8
n = list([int(i) for i in input()])
for i in range(len(n)-1):
    if n[i]%2==0 and n[i]<n[-1]:
        n[i], n[-1] = n[-1], n[i]
        print(''.join([str(ch) for ch in n]))
        break
else:
    for i in range(len(n)-1,-1,-1):
        if n[i]%2==0:
            n[i], n[-1] = n[-1], n[i]
            print(''.join([str(ch) for ch in n]))
            break
    else:
        print(-1)
