a, b, c = gets.split.collect{|i| i.to_i}
puts (a+b-1)*(a+c-1)-a*(a-1)
