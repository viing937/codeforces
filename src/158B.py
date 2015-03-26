# coding: utf-8
n = int(input())

cnt = [0]*5

for i in input().split():
    cnt[int(i)] += 1

ans = 0

# 4
t = cnt[4]
ans += t
cnt[4] -= t

# 3+1
t = min(cnt[1],cnt[3])
ans += t
cnt[1] -= t
cnt[3] -= t

# 2+2
t = cnt[2]//2
ans += t
cnt[2] -= t*2

# 2+1+1
t = min(cnt[2],cnt[1]//2)
ans += t
cnt[2] -= t
cnt[1] -= t*2

# 1+1+1+1
t = cnt[1]//4
ans += t
cnt[1] -= t*4

# 3
t = cnt[3]
ans += t
cnt[3] -= t

# 2+1
t = min(cnt[1],cnt[2])
ans += t
cnt[1] -= t
cnt[2] -= t

# 1+1+1
t = cnt[1]//3
ans += t
cnt[1] -= t*3

# 2
t = cnt[2]
ans += t
cnt[2] -= t

# 1+1
t = cnt[1]//2
ans += t
cnt[1] -= t*2

# 1
t = cnt[1]
ans += t
cnt[1] -= t 

print(ans)
