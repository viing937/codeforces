x, y = gets.split.collect{|i| i.to_i}
t = [x.abs, y.abs].max
ans = 4*t
if x == t and y == -t+1
    ans -= 4
elsif x == t and y > -t+1
    ans -= 3
elsif x < t and y == t
    ans -= 2
elsif x == -t and y < t
    ans -= 1
elsif x > -t and y == -t
    ans -= 0
end
puts ans
