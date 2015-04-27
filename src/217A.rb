n = gets.to_i
li = []
(1..n).each do
    x, y = gets.split.collect{|i| i.to_i}
    li.push([[x],[y]])
end
for i in (n-1).downto(0)
    for j in 0...i
        unless (li[j][0]&li[i][0]).empty? and (li[j][1]&li[i][1]).empty?
            li[j][0] |= li[i][0]
            li[j][1] |= li[i][1]
            li.delete_at(i)
            break
        end
    end
end
puts li.size-1
