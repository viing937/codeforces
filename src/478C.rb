c = gets.split.collect{|i| i.to_i}
s = c.inject(0){|sum, i| sum+=i}
if c.max <= (s-c.max)*2
    puts s/3
else
    puts s-c.max
end
