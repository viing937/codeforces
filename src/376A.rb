s = gets.chomp
fulcrum = s.index('^')
left = 0
right = 0
i = 1
while fulcrum-i >= 0
    left += i*s[fulcrum-i].to_i if s[fulcrum-i].to_i.to_s == s[fulcrum-i]
    i += 1
end
i = 1
while fulcrum+i < s.size
    right += i*s[fulcrum+i].to_i if s[fulcrum+i].to_i.to_s == s[fulcrum+i]
    i += 1
end
case left <=> right
when 1
    puts 'left'
when -1
    puts 'right'
when 0
    puts 'balance'
end
