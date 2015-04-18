n, m = gets.split.collect{|i| i.to_i}
a = gets.split.collect{|i| i.to_i}.select{|i| i<0}.sort
if a.size == 0
    puts 0
    exit
end
puts a[0,m].inject{|sum,i| sum+=i}.abs
