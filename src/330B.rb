require 'set'
n, m = gets.split.collect{|i| i.to_i}
mark = Set.new
for i in 0...m
    gets.split.collect{|i| i.to_i}.each{|i| mark.add(i)}
end
if not (Set.new(1..n)-mark).empty?
    puts n-1
    c = (Set.new(1..n)-mark).to_a[0]
    for i in 1..n
        print c, " ", i, "\n" if i!=c
    end
end
