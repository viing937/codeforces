n, m, t = gets.split.collect{|i| i.to_i}
ans = 0
b = 4
while b <= n
    ans += Array.new(n).combination(b).size * Array.new(m).combination(t-b).size if t-b>=1 and t-b<=m
    b += 1
end
puts ans
