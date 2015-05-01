n, m = 0, 0
File.open("input.txt", "r") do |file|
    n, m = file.gets.split.collect{|i| i.to_i}
end
File.open("output.txt", "w") do |file|
    if n >= m
        file.puts (['B','G']*m+['B']*(n-m)).join
    else
        file.puts (['G','B']*n+['G']*(m-n)).join
    end
end
