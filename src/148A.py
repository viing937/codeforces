# coding: utf-8
k = int(input())
l = int(input())
m = int(input())
n = int(input())
d = int(input())

dd = list(range(1,d+1))
kk = list(range(k,d+1,k))
ll = list(range(l,d+1,l))
mm = list(range(m,d+1,m))
nn = list(range(n,d+1,n))

dd = list(set(dd)-set(kk)) 
dd = list(set(dd)-set(ll)) 
dd = list(set(dd)-set(mm)) 
dd = list(set(dd)-set(nn)) 

print(d-len(dd))
