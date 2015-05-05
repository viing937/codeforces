n = gets.to_i
a = gets.split.collect{|i| i.to_i}
a = a.sort
if a.pop != 1
    puts ([1]+a).join(" ")
else
    puts (a+[2]).join(" ")
end
