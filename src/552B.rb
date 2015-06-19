n = gets.chomp
ans = 0
num = 9
(1...n.size).each do |i|
    ans += i*num
    num *= 10
end
ans += n.size*(n.to_i-10**(n.size-1)+1)
puts ans
