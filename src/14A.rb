n, m = gets.split.collect{|i| i.to_i}
s = Array.new(n)
n.times{|i| s[i] = gets.chomp}
up, low, left, right = 0, n-1, m-1, m-1
(0...n).each do |i|
    if s[i].include?("*")
        up = i
        break
    end
end
(n-1).downto(0).each do |i|
    if s[i].include?("*")
        low = i
        break
    end
end
(0...n).each{|i| left = s[i].index("*") if s[i].index("*") and s[i].index("*")<left}
(0...n).each{|i| right = s[i].reverse.index("*") if s[i].index("*") and s[i].reverse.index("*")<right}
right = m-right
(up..low).each{|i| puts s[i][left...right]}
