k, d = gets.split.collect{|i| i.to_i}
if d == 0
    if k == 1
        puts 0
    else
        puts 'No solution'
    end
    exit
end
puts (Array.new([d])+Array.new(k-1,0)).join
