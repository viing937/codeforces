n = gets.to_i
a = gets.split.collect{|i| i.to_i}
g = a[0]
a.each{|i| g=g.gcd(i)}
if ((g..a.max).step(g).size-a.size).odd?
    puts "Alice"
else
    puts "Bob"
end
