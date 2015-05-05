require 'set'
lines = gets(nil)
user = Set.new
ans = 0
lines.split("\n").each do |line|
    if line[0] == "+"
        user.add(line[1,line.size-1])
    elsif line[0] == "-"
        user.delete(line[1,line.size-1])
    else
        ans += user.size * line.split(":")[1].size if line.split(":")[1]
    end
end
puts ans
