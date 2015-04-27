n, m = gets.split.collect{|i| i.to_i}
v = gets.split.collect{|i| i.to_i}
ans = 0
(1..m).each do
    tmp = gets.split.collect{|i| i.to_i}
    ans += [v[tmp[0]-1],v[tmp[1]-1]].min
end
puts ans
