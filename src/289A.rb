n, k = gets.split.collect{|i| i.to_i}
cnt = 0
(0...n).each do
    l, r = gets.split.collect{|i| i.to_i}
    cnt += r-l+1
end
if cnt%k == 0
    puts "0"
else
    puts k-cnt%k
end
