n, l, r, x = gets.split.collect{|i| i.to_i}
c = gets.split.collect{|i| i.to_i}.sort
ans = 0
(2..n).each do |i|
    c.combination(i).each do |cc|
        sum = cc.inject{|sum,ccc| sum+=ccc}
        if sum >= l and sum <= r and cc[-1]-cc[0] >= x
            ans += 1
        end
    end 
end
puts ans
