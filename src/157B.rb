n = gets.to_i
r = gets.split.collect{|i| i.to_i}.sort.reverse
r.push(0)
ans = 0
for i in (0...n).step(2)
    ans += Math::PI*(r[i]*r[i]-r[i+1]*r[i+1])
end
puts ans
