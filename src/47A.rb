n = gets.to_i
t = ((n*2)**(0.5)).floor
if t*(t+1)==n*2
    puts "YES"
else
    puts "NO"
end
