n = gets.to_i
s = gets.chomp
ans = 0
(n...s.size).step(n).each{|i| ans += 1 if s[i-3]==s[i-2] and s[i-2]==s[i-1]}
puts ans
