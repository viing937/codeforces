def findf(x, fa)
    if fa[x] != 0
        findf(fa[x], fa)
    else
        x
    end
end
n, m = gets.split.collect{|i| i.to_i}
fa = Array.new(n+1,0)
cnt = Array.new(n+1,1)
m.times do
    x, y = gets.split.collect{|i| i.to_i}
    xx = findf(x, fa)
    yy = findf(y, fa)
    if xx != yy
        fa[yy] = xx
        cnt[xx] += cnt[yy]
    end
end
ans = 0
(1..n).each do |i|
    ans += cnt[i]-1 if fa[i]==0
end
puts 2**ans
