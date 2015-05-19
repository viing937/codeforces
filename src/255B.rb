s = gets.chomp
cntx = s.count("x")
cnty = s.count("y")
if cntx > cnty
    puts "x"*(cntx-cnty)
else
    puts "y"*(cnty-cntx)
end
