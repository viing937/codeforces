n, k = gets.split.collect{|i| i.to_i}
if n*3 >= k
    puts n*3-k
else
    puts 0
end
