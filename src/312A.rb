n = gets.to_i
(0...n).each do
    s = gets.chomp
    if s.size < 5
        puts "OMG>.< I don't know!"
    elsif s[0,5] == "miao." and s[s.size-5,5] != "lala."
        puts "Rainbow's"
    elsif s[0,5] != "miao." and s[s.size-5,5] == "lala."
        puts "Freda's"
    else
        puts "OMG>.< I don't know!"
    end
end
