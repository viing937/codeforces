s = gets.chomp
k = gets.to_i
if s.size%k != 0
    puts "NO"
    exit
end
len = s.size/k
(0...s.size).step(len).each do |i|
    if s[i,len] != s[i,len].reverse
        puts "NO"
        exit
    end 
end
puts "YES"
