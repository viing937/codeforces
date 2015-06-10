n = gets.to_i
a = gets.split.collect{|i| i.to_i}
ans = 0
n.times do |i|
    ans += (i+1)*(a[i]-1)+1
end
puts ans
