n, m = gets.split.collect{|i| i.to_i}
flag = -1
(1..n).each do
    tmp = gets.chomp.split("").collect{|i| i.to_i}
    if flag == tmp[0] or tmp.count(tmp[0]) != m
        puts "NO"
        exit
    end
    flag = tmp[0]
end
puts "YES"
