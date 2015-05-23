k, n, w = gets.split.collect{|i| i.to_i}
puts [(w+1)*w/2*k-n,0].max
