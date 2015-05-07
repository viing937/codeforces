n = gets.to_i
l = Hash.new(0)
ll = Hash.new(0)
gets.split.each{|i| l[i.to_i]+=1}
l = l.sort_by{|key, value| key}.reverse
(0...l.size).each do |i|
    if i > 0 and l[i-1][0] == l[i][0]+1 and l[i-1][1] > 0 and l[i][1] > 0
        ll[l[i][0]] += 1
        l[i-1][1] = 0
        l[i][1] -= 1
    end
    if l[i][1] >= 2
        ll[l[i][0]] += l[i][1]/2
        l[i][1] %= 2
    end
end
ll = ll.sort_by{|key, value| key}.reverse
ans = 0
(0...ll.size).each do |i|
    if ll[i][1] >= 2
        ans += ll[i][1]/2*ll[i][0]*ll[i][0]
        ll[i][1] %= 2
    end
    if ll[i][1] > 0 and i < ll.size-1
        ans += ll[i][0]*ll[i+1][0]
        ll[i][1] = 0
        ll[i+1][1] -= 1
    end
end
puts ans
