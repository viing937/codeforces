ranks = {"6"=>0, "7"=>1, "8"=>2, "9"=>3, "T"=>4, "J"=>5, "Q"=>6, "K"=>7, "A"=>8}
trump = gets.chomp
first, second = gets.split
if (first[1] == trump and second[1] != trump) or
   (first[1] == second[1] and ranks[first[0]] > ranks[second[0]])
    puts "YES"
else
    puts "NO"
end
