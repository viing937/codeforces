# coding: utf-8
str_1 = input()
str_2 = input()

str_1 = str_1.lower()
str_2 = str_2.lower()

if str_1 < str_2:
    print('-1')
elif str_1 == str_2:
    print('0')
else:
    print('1')
