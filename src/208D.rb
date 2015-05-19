n = gets.to_i
p = gets.split.collect{|i| i.to_i}
c = gets.split.collect{|i| i.to_i}
ans = Array.new(5,0)
points = 0
p.each do |pp|
    points += pp
    4.downto(0).each do |i|
        ans[i] += points/c[i]
        points = points%c[i]
    end
end
puts ans.join(" ")
puts points
