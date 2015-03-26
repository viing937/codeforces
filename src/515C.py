# coding: utf-8
n = int(input())
cnt = [] 
for i in input():
    if i == '2':
        cnt.append('2')
    elif i == '3':
        cnt.append('3')
    elif i == '4':
        cnt.append('2')
        cnt.append('2')
        cnt.append('3')
    elif i == '5':
        cnt.append('5')
    elif i == '6':
        cnt.append('3')
        cnt.append('5')
    elif i == '7':
        cnt.append('7')
    elif i == '8':
        cnt.append('2')
        cnt.append('2')
        cnt.append('2')
        cnt.append('7')
    elif i == '9':
        cnt.append('2')
        cnt.append('3')
        cnt.append('3')
        cnt.append('7')
cnt.sort(reverse=True)
print(''.join(cnt))
