n = gets.to_i
if n == 1
    puts "1"
elsif n == 2
    puts "2"
elsif (n%2).zero? and (n%3).zero?
    puts (n-1)*(n-2)*(n-3)
elsif (n%2).zero? and not (n%3).zero?
    puts n*(n-1)*(n-3)
else
    puts n*(n-1)*(n-2)
end
