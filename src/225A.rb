n = gets.to_i
top = gets.to_i
(1..n).each do
    left, right = gets.split.collect{|i| i.to_i}
    if left == top or 7-left == top or\
       right == top or 7-right == top
        puts 'NO'
        exit
    end
end
puts 'YES'
