n = gets.to_i
s = gets.chomp
li = Array.new
for i in 0...n
    if s[i] == 'L' or s[i] == 'R'
        li.push(i)
    end
end
if li.empty?
    puts n
    exit
end
ans = 0
if s[li[0]] == 'R'
    ans += li[0]
end
if s[li[-1]] == 'L'
    ans += n-1-li[-1]
end
for i in 1...li.length
    if s[li[i-1]]=='R' and s[li[i]]=='L' and (li[i]-li[i-1]).even?
        ans += 1
    elsif s[li[i-1]]=='L' and s[li[i]]=='R'
        ans += li[i]-li[i-1]-1
    end
end
puts ans
