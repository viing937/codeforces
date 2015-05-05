n = gets.to_i
li = []
(0...n).each{li.push(gets.split.collect{|i| i.to_i})}
li = li.sort_by{|i| [i[1], i[0]]}
ans = 0
cnt = 1
li.reverse.each do |i|
    ans += i[0]
    cnt += i[1]-1
    break if cnt.zero?
end
puts ans
