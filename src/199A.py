# coding: utf-8
n = int(input())
if n == 0:
    print(0,0,0)
    exit()
if n == 1:
    print(0,0,1)
    exit()
fibonacci = [0,1,1,2]
while fibonacci[-1] != n:
    fibonacci.append(fibonacci[-1]+fibonacci[-2])
print(fibonacci[-4],fibonacci[-3],fibonacci[-3])
