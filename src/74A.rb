n = gets.to_i
ans = ""
score = -(1<<30)
n.times do
    tmp = gets.split
    (1..7).each{|i| tmp[i] = tmp[i].to_i}
    tmpscore = tmp[1]*100-tmp[2]*50+tmp[3]+tmp[4]+tmp[5]+tmp[6]+tmp[7]
    if tmpscore > score
        score = tmpscore
        ans = tmp[0]
    end
end
puts ans
