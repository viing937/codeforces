n = gets.to_i
a = gets.split.collect{|i| i.to_i}
ans = nil
amin = a.min
a.each{|aa| ans = aa if aa > amin and (ans == nil or aa < ans)}
if ans == nil
    puts "NO"
else
    puts ans
end
