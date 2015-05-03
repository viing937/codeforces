n, k = gets.split.collect{|i| i.to_i}
a = gets.split.collect{|i| i.to_i}
ans = 0
(0...k).each do |i|
    j = 0
    tmp = Array.new
    while i+j < n
        tmp.push(a[i+j])
        j += k
    end
    ans += [tmp.count(1), tmp.count(2)].min
end
puts ans
