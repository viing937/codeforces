# coding: utf-8
n = int(input())
string = input()
string_new = []
for i in range(n):
    if i==0 or string[i]!=string[i-1]:
        string_new.append(string[i])
print(len(string)-len(string_new))
