n = gets.to_i
a = gets.split.collect{|i| i.to_i}
ans = 0
(1...n-1).each{|i| ans = i if (a[i]-a[i+1]).abs < (a[ans]-a[ans+1]).abs}
if (a[0]-a[n-1]).abs < (a[ans]-a[ans+1]).abs
    print n, " ", 1, "\n"
else
    print ans+1, " ", ans+2, "\n"
end
