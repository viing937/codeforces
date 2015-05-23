n, k = gets.split.collect{|i| i.to_i}
s = Array.new(n){Array.new(n,"S")}
if n.odd?
    if k > n*n/2+1
        puts "NO"
        exit
    end
else
    if k > n*n/2
        puts "NO"
        exit
    end
end
i = 0
j = 0
k.times do
    s[i][j] = "L"
    j += 2
    if j >= n
        i += 1
        j = i%2
    end
end
puts "YES"
s.each{|str| puts str.join}
