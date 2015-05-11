n, k = gets.split.collect{|i| i.to_i}
a = gets.split.collect{|i| i.to_i}.sort
ans = 0
cnt = 0
a.each{|i| cnt+=1 if i<=0}
if cnt>=k
    n.times do |i|
        if i < k
            ans += -a[i]
        else
            ans += a[i]
        end
    end
else
    k -= cnt
    a = a.collect{|i| i.abs}
    if k.odd?
        ans = a.inject{|sum, i| sum+=i}-2*a.min
    else
        ans = a.inject{|sum, i| sum+=i}
    end
end
puts ans
