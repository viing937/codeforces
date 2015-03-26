# coding: utf-8
a = int(input())
b = 0
while True:
    b += 1
    for ch in str(a+b):
        if ch == '8':
            print(b)
            exit()
