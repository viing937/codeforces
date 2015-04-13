s = gets
num = Hash.new
for i in 0...10
    num[gets.chomp] = i
end
for i in 0...8
    print num[s[10*i...10*i+10]]
end
puts
