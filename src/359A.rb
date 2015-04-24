n, m = gets.split.collect{|i| i.to_i}
a = Array.new(n)
(0...n).each do |i|
    a[i] = gets.split
end
if a[0].count("1") > 0 or a[n-1].count("1") > 0 or\
   a.transpose[0].count("1") > 0 or a.transpose[m-1].count("1") > 0
    puts 2
else
    puts 4
end
