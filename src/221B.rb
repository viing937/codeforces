x = gets.to_i
xset = x.to_s.split("")
ans = 0
(1..x**0.5).each do |i|
    next if x%i != 0
    ans += 1 unless (i.to_s.split("")&xset).empty?
    j = x/i
    if j != i
        ans += 1 unless (j.to_s.split("")&xset).empty?
    end
end
puts ans
