s = gets.reverse.chars
for ch in s
    if ch =~ /[a-zA-Z]/
        if ch =~ /[aeiouyAEIOUY]/
            puts "YES"
        else
            puts "NO"
        end
        break
    end
end
