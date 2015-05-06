a, b = gets.split.collect{|i| i.to_i}
ans = 0
while b != 1
    a, b = b, a if a < b 
    ans += a/b
    a = a%b
end
puts ans+a
