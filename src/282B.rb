n = gets.to_i
sa = 0
sg = 0
(0...n).each do |i|
    a, g = gets.split.collect{|i| i.to_i}
    if (sa+a-sg).abs <= 500
        sa += a
        print "A"
    else
        sg += g
        print "G"
    end
end
print "\n"
