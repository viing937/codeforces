c = gets.split.collect{|i| i.to_i}.sort_by{|i| i%3}
ans = 0
3.times{|i| ans += c[i]/3}
if c[0]%3==0 and c[1]%3==2 and c[2]%3==2 and c[0] > 0
    ans += 1
else
    ans += c[0]%3
end
puts ans
