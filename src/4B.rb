d, sumtime = gets.split.collect{|i| i.to_i}
limittime = (1..d).collect{gets.split.collect{|i| i.to_i}}
if limittime.inject(0){|mintime, i| mintime+i[0]} > sumtime or\
   limittime.inject(0){|maxtime, i| maxtime+i[1]} < sumtime
    puts 'NO'
    exit
end
ans = limittime.collect{|i| i[0]}
sumtime -= ans.inject(0){|sum,i| sum+i}
for i in 0...d
    if sumtime > limittime[i][1]-ans[i]
        sumtime -= limittime[i][1]-ans[i]
        ans[i] = limittime[i][1]
    else
        ans[i] += sumtime
        sumtime = 0
        break
    end
end
puts 'YES'
puts ans.join(' ')
