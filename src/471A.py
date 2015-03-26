# coding: utf-8
l = [int(i) for i in input().split()]
ll = set(l)
for s in ll:
    if l.count(s) >= 4:
        temp = list(l)
        for i in range(4):
            temp.remove(s)
        temp.sort()
        if temp[0] == temp[1]:
            print('Elephant')
        else:
            print('Bear')
        break
else:
    print('Alien')
