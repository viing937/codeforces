n, m = gets.split.collect{|i| i.to_i}
if n == 0 and m != 0
    puts "Impossible"
elsif m == 0
    puts [n, n].join(" ")
else
    puts [n+m-[n,m].min, n+m-1].join(" ")
end
