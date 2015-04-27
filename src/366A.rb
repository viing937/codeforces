n = gets.to_i
(1..4).each do |i|
    a, b, c, d = gets.split.collect{|j| j.to_i}
    x = [a,b].min
    y = [c,d].min
    if x+y <= n
        print i, " ", x, " ", n-x, "\n"
        exit
    end
end
puts -1
