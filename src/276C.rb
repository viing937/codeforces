n, q = gets.split.collect{|i| i.to_i}
a = gets.split.collect{|i| i.to_i}.sort.reverse
s = Array.new(n+1,0)
q.times do
    l, r = gets.split.collect{|i| i.to_i-1}
    s[l] += 1
    s[r+1] -= 1
end
n.times do |i|
    s[i+1] += s[i]
end
s = s.sort.reverse
puts (0...n).inject(0){|sum, i| sum += s[i]*a[i]}
