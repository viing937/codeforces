n, m = gets.split.collect{|i| i.to_i}
if m < n-1 or m > (n+1)*2
    puts -1
elsif m == n-1
    puts (['0']*n).join('1')
elsif m == n
    puts (['0']*n).join('1')+'1'
else
    cnt = m-n-1
    puts (['11']*cnt+['1']*(n+1-cnt)).join('0')
end
