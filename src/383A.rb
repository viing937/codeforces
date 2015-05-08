n = gets.to_i
a = gets.split.collect{|i| i.to_i}
ans = Array.new(2,0)
cnt = 0
(1...n).each do |i|
    cnt += 1 if a[i-1] == 1
    ans[0] += cnt if a[i]== 0
end
cnt = 0
(n-2).downto(0).each do |i|
    cnt += 1 if a[i+1] == 0
    ans[1] += cnt if a[i]== 1
end
puts ans.min
