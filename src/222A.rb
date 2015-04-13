n, k = gets.split.collect{|i| i.to_i}
a = Array.new(gets.split)
if a[k-1..-1].uniq.length == 1
    ans = k-2
    while ans >= 0 and a[ans] == a[-1]
        ans -= 1
    end
    puts ans+1
else
    puts -1
end
