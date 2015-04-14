n, k = gets.split.collect{|i| i.to_i}
s = Array.new(n){Array.new(n,k/n)}
for i in 0...n
    s[i][i] += k%n
end
s.collect{|i| puts i.join(' ')}
