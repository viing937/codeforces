n = gets.to_i
blocks = gets.chomp
s = blocks.index("R")
if s
    puts [s+1, n-blocks.reverse.index("R")+1].join(" ")
    exit
end
t = blocks.index("L")
if t
    puts [n-blocks.reverse.index("L"),t].join(" ")
end
