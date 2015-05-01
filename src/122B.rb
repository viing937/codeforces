s = gets.chomp
cnt1 = s.count("4")
cnt2 = s.count("7")
if cnt1 == 0 and cnt2 == 0
    puts -1
elsif cnt1 >= cnt2
    puts 4
else
    puts 7
end
