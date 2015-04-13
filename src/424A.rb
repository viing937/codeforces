n = gets.to_i
s = gets
ans = s.count('x')-n/2
if ans > 0
    for i in 0...ans.abs
        s[s.index('x')] = 'X'
    end
else
    for i in 0...ans.abs
        s[s.index('X')] = 'x'
    end
end
puts ans.abs
puts s
