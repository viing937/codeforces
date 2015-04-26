a = gets.chomp
b = gets.chomp
x = 0
y = 0
(0...a.size).each do |i|
    if a[i] == '7' and b[i] == '4'
        x += 1
    elsif a[i] == '4' and b[i] == '7'
        y += 1
    end
end
puts [x,y].max
