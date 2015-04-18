n, k = gets.split.collect{|i| i.to_i}
a = gets.split.collect{|i| i.to_i}
ans = Array.new
cnt = 0
while cnt < k
    min, max = a.minmax
    if max-min <= 1
        break
    end
    minindex = a.index(min)
    maxindex = a.index(max)
    a[maxindex] -= 1
    a[minindex] += 1
    ans.push([maxindex+1, minindex+1])
    cnt += 1
end
min, max = a.minmax
print max-min, ' ', cnt, "\n"
ans.each{|i| puts i.join(' ')}
