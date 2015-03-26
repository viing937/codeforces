# coding: utf-8
n = int(input())
mod_1 = [1]
mod_2 = [6,2,4,8]
mod_3 = [1,3,9,7]
mod_4 = [6,4]
ans = (mod_1[n%1]+mod_2[n%4]+mod_3[n%4]+mod_4[n%2])%5
print(ans)
