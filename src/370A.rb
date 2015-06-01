r1, c1, r2, c2 = gets.split.collect{|i| i.to_i}
if r1==r2 and c1==c2
    rook = 0
elsif r1==r2 or c1==c2
    rook = 1
else
    rook = 2
end
if (r1+c1)%2 != (r2+c2)%2
    bishop = 0
elsif r1+c1==r2+c2 or r1+c2==r2+c1
    bishop = 1
else
    bishop = 2
end
king = [(r1-r2).abs,(c1-c2).abs].max
puts [rook,bishop,king].join(" ")
