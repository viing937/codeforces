n, m, k = gets.split.collect{|i| i.to_i}
a = gets.split.collect{|i| i.to_i}.sort.reverse
s = k
ans = 0
while s < m and ans < n
    s = s-1+a[ans]
    ans += 1
end
if s < m
    puts "-1"
else
    puts ans
end
