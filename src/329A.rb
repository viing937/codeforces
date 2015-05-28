n = gets.to_i
s = Array.new(n)
n.times{|i| s[i] = gets.chomp.split("")}
ans = Array.new
n.times do |i|
    ans.push(s[i].index(".")) if s[i].index(".")
end
if ans.size >= n
    n.times{|i| puts [i+1, ans[i]+1].join(" ")}
    exit
end
ans.clear
s = s.transpose
n.times do |i|
    ans.push(s[i].index(".")) if s[i].index(".")
end
if ans.size >= n
    n.times{|i| puts [ans[i]+1, i+1].join(" ")}
    exit
end
puts "-1"
