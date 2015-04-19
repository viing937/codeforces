n = gets.to_i
a = gets.split.collect{|i| i.to_i}
if a.size < 3
    puts a.size
    exit
end
maxlength = 2
thislength = 2
for i in 2...n
    if a[i] == a[i-1]+a[i-2]
        thislength += 1
        maxlength = thislength if thislength > maxlength
    else
        thislength = 2
    end
end
puts maxlength
