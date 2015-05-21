n = gets.to_i
ans = Array.new
n.times do |i|
    tmp = gets.split
    ans.push(i+1) if not tmp.include?("1") and not tmp.include?("3")
end
puts ans.size
puts ans.join(" ") unless ans.empty?
