require 'set'
n = gets.to_i
a = Set.new
b = Set.new
map = Hash.new
(0...n).each do |i|
    aa, bb = gets.split.collect{|j| j.to_i}
    a.add(aa)
    b.add(bb)
    map[aa] = bb
end
ans = Array.new(n)
ans[0] = (a-b).to_a[0]
ans[1] = map[0]
for i in 2...n
    ans[i] = map[ans[i-2]]
end
puts ans.join(" ")
