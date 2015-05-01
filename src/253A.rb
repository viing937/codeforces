n, m = File.new("input.txt", "r").gets.split.collect{|i| i.to_i}
if n >= m
    File.new("output.txt", "w").puts (['B','G']*m+['B']*(n-m)).join
else
    File.new("output.txt", "w").puts (['G','B']*n+['G']*(m-n)).join
end
