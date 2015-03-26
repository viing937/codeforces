# coding: utf-8
n = input()
print(max(int(n),int(n[:-1]),int(n[:-2]+n[-1:])))
