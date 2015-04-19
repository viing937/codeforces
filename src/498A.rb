x1, y1 = gets.split.collect{|i| i.to_i}
x2, y2 = gets.split.collect{|i| i.to_i}
n = gets.to_i
ans = 0
for i in 0...n
    a, b, c = gets.split.collect{|i| i.to_i}
    ans += 1 if (a*x1+b*y1+c)*(a*x2+b*y2+c) < 0
end
puts ans
