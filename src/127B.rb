n = gets.to_i
a = Hash.new(0)
gets.split.each{|i| a[i]+=1}
cnt = 0
a.each{|key,value| cnt+=value/2}
puts cnt/2
