phrases = Array.new
phrases.push(gets.split(""))
phrases.push(gets.split(""))
phrases.push(gets.split(""))
if phrases[0].count("a") + phrases[0].count("e") + phrases[0].count("i") + phrases[0].count("o") + phrases[0].count("u") == 5 and\
   phrases[1].count("a") + phrases[1].count("e") + phrases[1].count("i") + phrases[1].count("o") + phrases[1].count("u") == 7 and\
   phrases[2].count("a") + phrases[2].count("e") + phrases[2].count("i") + phrases[2].count("o") + phrases[2].count("u") == 5
    puts "YES"
else
    puts "NO"
end
