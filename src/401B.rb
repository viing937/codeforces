x, k = gets.split.collect{|i| i.to_i}
mark = Array.new(x-1,0)
(1..k).each do
    tmp = gets.split.collect{|i| i.to_i}
    mark[tmp[1]-1] = 1
    mark[tmp[2]-1] = 1 if tmp.size == 3
end
maxans = mark.count(0)
minans = maxans
tmp = 1
while tmp < x
    if mark[tmp] == 0 and mark[tmp-1] == 0
        minans -= 1
        tmp += 1
    end
    tmp += 1
end
print minans, " ", maxans, "\n"
