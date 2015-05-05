a = {">"=>"1000", "<"=>"1001", "+"=>"1010", "-"=>"1011", "."=>"1100", ","=>"1101", "["=>"1110", "]"=>"1111"}
ans = Array.new
gets.chomp.split("").each do |i|
    ans.push(a[i])
end
puts ans.join.to_i(2)%1000003
