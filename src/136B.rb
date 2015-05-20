a, c = gets.split.collect{|i| i.to_i.to_s(3)}
length = [a.size,c.size].max
a = "0"*(length-a.size)+a
c = "0"*(length-c.size)+c
b = "0"*length
length.times do |i|
    b[i] = ((c[i].to_i+3-a[i].to_i)%3).to_s
end
puts b.to_i(3)
