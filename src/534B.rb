v1, v2 = gets.split.collect{|i| i.to_i}.minmax
t, d = gets.split.collect{|i| i.to_i}
if d.zero?
    puts v1*t
    exit
end
x = ((1.0*d*t+v2-v1)/(2*d)).round
ans = v1*x+d*(x-1)*x/2 + v2*(t-x)+d*(t-x-1)*(t-x)/2
puts ans
