n, k = gets.split.collect{|i| i.to_i}
if n/2 > k
    puts -1
elsif n == 1
    if k > 0
        puts -1
    else
        puts 1
    end
else
    ans = Array.new(n)
    ans[0] = k-n/2+1
    ans[1] = 2*ans[0]
    for i in 2...n
        ans[i] = ans[i-1]+1
    end
    puts ans.join(' ')
end
