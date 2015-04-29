a, b = gets.split.collect{|i| i.to_i}
puts (b*(b-1)/2)*((1+a)*a*b/2+a)%1000000007 
