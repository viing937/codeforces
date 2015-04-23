n, v = gets.split.collect{|i| i.to_i}
num = Hash.new(0)
(0...n).each do
    tmp = gets.split.collect{|i| i.to_i}
    num[tmp[0]] += tmp[1]
end
ans = 0
(1..3001).each do |i|
    tmp = [num[i-1], v].min
    ans += tmp
    tmp = v-tmp
    if tmp > 0
        if tmp >= num[i]
            ans += num[i]
            num[i] = 0
        else
            ans += tmp
            num[i] -= tmp
        end
    end
end
puts ans
