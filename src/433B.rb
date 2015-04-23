n = gets.to_i
v = [0] + gets.split.collect{|i| i.to_i}
u = v.sort
(1..n).each do |i|
    v[i] += v[i-1]
    u[i] += u[i-1]
end
m = gets.to_i
(0...m).each do
    type, l, r = gets.split.collect{|i| i.to_i}
    if type == 1
        puts v[r]-v[l-1]
    else
        puts u[r]-u[l-1]
    end
end
