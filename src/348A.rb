n = gets.to_i
a = gets.split.collect{|i| i.to_i}
amax = a.max
ans = 0
a.each{|aa| ans += amax-aa}
if amax <= ans
    puts amax
else
    amax -= ans
    ans += amax/(n-1)*n
    amax %= n-1
    ans += amax+1 if amax > 0
    puts ans
end
