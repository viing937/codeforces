r1, r2 = gets.split.collect{|i| i.to_i}
c1, c2 = gets.split.collect{|i| i.to_i}
d1, d2 = gets.split.collect{|i| i.to_i}
(1..9).each do |i|
    (1..9).each do |j|
        (1..9).each do |k|
            (1..9).each do |l|
                if i+j==r1 and k+l==r2 and i+k==c1 and j+l==c2 and i+l==d1 and j+k==d2 and [i,j,k,l].uniq.size==4
                    puts [i,j].join(" ")
                    puts [k,l].join(" ")
                    exit
                end
            end
        end
    end
end
puts "-1"
