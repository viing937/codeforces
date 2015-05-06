n, m = gets.split.collect{|i| i.to_i}
pre = gets.split.collect{|i| i.to_i}
ans = pre[1]+pre[0]-1
(1...m).each do
    tmp = gets.split.collect{|i| i.to_i}
    t = tmp[0]-pre[0]
    v1, v2 = [pre[1], tmp[1]].minmax
    x = (1.0*t+v2-v1)/2
    if x < 0 or x > t
        puts "IMPOSSIBLE"
        exit
    end
    x = x.round
    ans = [ans,v1+x-1,v2+t-x].max
    pre = tmp
end
ans = [ans,pre[1]+n-pre[0]].max
puts ans
