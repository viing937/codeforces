n = gets.to_i
pos = Hash.new
tmp = 1
gets.split.each do |a|
    pos[a.to_i]=tmp
    tmp += 1
end
tmp = 0
m = gets.to_i
gets.split.each do |b|
    tmp+=pos[b.to_i]
end
print tmp, " ", (n+1)*m-tmp, "\n"
