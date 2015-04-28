n = gets.chomp.split("").collect{|i| i.to_i}
k = n.max
ans = Array.new(k){Array.new}
n.each do |i|
    for j in 0...i
        ans[j].push('1')
    end
    for j in i...k
        ans[j].push('0')
    end
end
ans = ans.collect{|i| i.join.to_i}
puts k
puts ans.join(" ")
