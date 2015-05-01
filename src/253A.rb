file = File.new("input.txt", "r")
n, m = file.gets.split.collect{|i| i.to_i}
file.close
file = File.new("output.txt", "w")
if n >= m
    file.puts (['B','G']*m+['B']*(n-m)).join
else
    file.puts (['G','B']*n+['G']*(m-n)).join
end
file.close
