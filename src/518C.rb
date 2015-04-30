n, m, k = gets.split.collect{|i| i.to_i}
a = gets.split.collect{|i| i.to_i}
mark = Hash.new
(0...a.size).each{|i| mark[a[i]] = i}
ans = 0
gets.split.each do |b|
    tmp = mark[b.to_i]
    if tmp != 0
        ans += tmp/k+1
        mark[a[tmp]] -= 1
        mark[a[tmp-1]] += 1
        a[tmp-1], a[tmp] = a[tmp], a[tmp-1]
    else
        ans += 1
    end
end
puts ans
