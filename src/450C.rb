n, m, k = gets.split.collect{|i| i.to_i}
n, m = m, n if n > m
if k < n
    ans = [(n/1)*(m/(k+1)), (n/(k+1))*(m/1)].max
elsif k >= n and k < m
    ans = (n/1)*(m/(k+1))
elsif k >= m and k <= m+n-2
    ans = (n/(k+2-m))*(m/m)
else
    ans = -1
end
puts ans
