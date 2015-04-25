n = gets.to_i
xx = Array.new(2,0)
yy = Array.new(2,0)
(1..n).each do
    t, x, y = gets.split.collect{|i| i.to_i}
    xx[t-1] += x
    yy[t-1] += y
end
(0..1).each do |i|
    if xx[i] >= yy[i]
        puts 'LIVE'
    else
        puts 'DEAD'
    end
end
