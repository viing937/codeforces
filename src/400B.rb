n, m = gets.split.collect{|i| i.to_i}
ans = Array.new(n)
n.times do |i|
    s = gets.chomp
    d = s.index("G")
    c = s.index("S")
    if d > c
        puts -1
        exit
    end
    ans[i] = c-d
end
puts ans.uniq.size
