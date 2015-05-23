n = gets.to_i
a = gets.split.collect{|i| i.to_i}.sort
ans = 0
cur = a[0]
(1...n).each do |i|
    if a[i] <= cur
        ans += cur-a[i]+1
        cur += 1
    else
        cur = a[i]
    end
end
puts ans
