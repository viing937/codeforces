a, b, n = gets.split.collect{|i| i.to_i}
(0...10).each do |i|
    if (a*10+i)%b==0
        print a, i, "0"*(n-1), "\n"
        exit
    end
end
puts -1
