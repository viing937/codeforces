# coding: utf-8
vowels = ['a','o','y','e','u','i']

string = input()
string = string.lower()
        
for ch in string:
    if ch not in vowels:
        print('.'+ch, end='' )

print('')
