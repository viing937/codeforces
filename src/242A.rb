x, y, a, b = gets.split.collect{|i| i.to_i}
cnt = 0
for i in a..x
    for j in b...(i<y+1 ? i : y+1)
        cnt += 1
    end
end
puts cnt
for i in a..x
    for j in b...(i<y+1 ? i : y+1)
        print i, " ", j, "\n"
    end
end
