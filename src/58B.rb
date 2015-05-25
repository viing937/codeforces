n = gets.to_i
divisors = Array.new
(1..n**0.5).each do |i|
    next if n%i != 0
    divisors.push(i)
    divisors.push(n/i)
end
divisors = divisors.uniq.sort
lcm = 1
ans = Array.new
divisors.each do |divisor|
    next if divisor % lcm != 0
    ans.push(divisor)
    lcm = lcm.lcm(divisor)
end
puts ans.reverse.join(" ")
