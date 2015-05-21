n = gets.to_i
t = gets.split.collect{|i| i.to_i}.sort
sum = 0
ans = 0
t.each do |tt|
    if tt >= sum
        sum += tt
        ans += 1
    end
end
puts ans
