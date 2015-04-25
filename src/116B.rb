n, m = gets.split.collect{|i| i.to_i}
mm = Array.new
(1..n).each{mm.push(gets.chomp.split(''))}
ans = 0
for i in 0...n
    for j in 0...m
        next unless  mm[i][j] == 'P'
        if i-1 >= 0 and mm[i-1][j] == 'W'
            mm[i-1][j] = '.'
            ans += 1
            next
        end
        if i+1 < n and mm[i+1][j] == 'W'
            mm[i+1][j] = '.'
            ans += 1
            next
        end
        if j-1 >= 0 and mm[i][j-1] == 'W'
            mm[i][j-1] = '.'
            ans += 1
            next
        end
        if j+1 < m and mm[i][j+1] == 'W'
            mm[i][j+1] = '.'
            ans += 1
            next
        end
    end
end
puts ans
