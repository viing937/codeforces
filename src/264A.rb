index = 0
s = gets.chomp
ans = Array.new
for i in 0...s.length
    if s[i] == 'r'
        puts i+1
    else
        ans.push(i+1)
    end
end
ans.reverse.each{|i| puts i}
