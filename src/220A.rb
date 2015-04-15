n = gets.to_i
a = gets.split.collect{|i| i.to_i}
b = a.sort
cnt = 0
for i in 0...n
    if a[i] != b[i]
        cnt += 1
    end
end
if cnt <= 2
    puts 'YES'
else
    puts 'NO'
end
