m, t, r = [int(i) for i in input().split()]
w = [int(i) for i in input().split()]
if r > t:
    print(-1)
    exit()
candles = list(range(w[0]-r,w[0]))
ans = r
for i in range(1,len(w)):
    candles = [candle for candle in candles if candle >= w[i]-t]
    dis = r-len(candles)
    candles += list(range(w[i]-dis,w[i]))
    ans += dis
print(ans)
