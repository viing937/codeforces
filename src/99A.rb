i, f = gets.chomp.split(".")
if i[-1] == "9"
    puts "GOTO Vasilisa."
elsif f[0] < "5"
    puts i
else
    puts i.to_i+1
end
