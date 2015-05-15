k = gets.to_i
q = gets.chomp
if q.split("").uniq.size < k
    puts "NO"
else
    puts "YES"
    tmp = q.split("").uniq[0, k]
    (k-1).times do |i|
        puts q[q.index(tmp[i])...q.index(tmp[i+1])]
    end
    puts q[q.index(tmp[-1])..-1]
end
