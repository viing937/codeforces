s = gets.chomp.split('')
m = gets.to_i
cnt = Array.new((s.length+1)/2+1,0)
gets.split.collect{|i| cnt[i.to_i]+=1}
for i in 1..(s.length+1)/2
    cnt[i] = (cnt[i-1]+cnt[i])%2
    if cnt[i] > 0
        s[i-1], s[s.length-i] = s[s.length-i], s[i-1]
    end
end
puts s.join
