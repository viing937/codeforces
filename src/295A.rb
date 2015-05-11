n, m, k = gets.split.collect{|i| i.to_i}
a = gets.split.collect{|i| i.to_i}
op = Array.new(m)
(0...m).each{|i| op[i] = gets.split.collect{|j| j.to_i}}

q = Array.new(m,0)
k.times do
    tmp = gets.split.collect{|i| i.to_i-1}
    q[tmp[0]] += 1
    q[tmp[1]+1] -= 1 if tmp[1]+1 < m
end
(1...m).each{|i| q[i] += q[i-1]}

dp = Array.new(n,0)
(0...m).each do |i|
    dp[op[i][0]-1] += op[i][2]*q[i]
    dp[op[i][1]] -= op[i][2]*q[i] if op[i][1] < n
end
(1...n).each{|i| dp[i] += dp[i-1]}
puts (0...n).collect{|i| a[i]+dp[i]}.join(" ")
