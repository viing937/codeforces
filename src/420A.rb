s = gets.chomp
letters = ["A", "H", "I", "M", "O", "T", "U", "V", "W", "X", "Y"]
unless (s.split("").uniq-letters).empty?
    puts "NO"
    exit
end
if s.reverse != s
    puts "NO"
    exit
end
puts "YES"
