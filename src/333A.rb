n = gets.to_i
t = 1
while n%t==0
    t *= 3
end
ans = n/t+1
puts ans
