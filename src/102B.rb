s = gets.chomp.split("").collect{|i| i.to_i}
ans = 0
while s.size > 1
    ans += 1
    s = s.inject{|sum,i| sum+=i}.to_s.split("").collect{|i| i.to_i}
end
puts ans
