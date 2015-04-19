n = gets.to_i
a = gets.split.collect{|i| i.to_i}
if a.inject(0){|sum,i| sum+i}%n == 0
    puts n
else
    puts n-1
end
