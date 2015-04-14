n = gets.to_i
if n==1 or n==2
    print "1\n1\n"
    exit
elsif n==3
    print "2\n1 3\n"
    exit
elsif n==4
    print "4\n3 1 4 2\n"
    exit
end
puts n
puts ((1..n).step(2).to_a+(2..n).step(2).to_a).join(' ')
