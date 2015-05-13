c = gets.split.collect{|i| i.to_i}
n, m = gets.split.collect{|i| i.to_i}
sum_a = 0
gets.chomp.split.each do |a|
    sum_a += [a.to_i*c[0],c[1]].min
end
sum_a = c[2] if sum_a > c[2]
sum_b = 0
gets.chomp.split.each do |b|
    sum_b += [b.to_i*c[0],c[1]].min
end
sum_b = c[2] if sum_b > c[2]
puts [sum_a+sum_b, c[3]].min
