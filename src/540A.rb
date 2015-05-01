n = gets.to_i
origin = gets.split("").collect{|i| i.to_i}
destin = gets.split("").collect{|i| i.to_i}
ans = 0
(0...n).each do |i|
    tmp = (origin[i]-destin[i]).abs
    ans += [tmp,10-tmp].min
end
puts ans
