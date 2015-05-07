n, m = gets.split.collect{|i| i.to_i}
ans = [n, m].min+1
puts ans
(0...ans).each do |i|
    print i, " ", ans-1-i, "\n" 
end
