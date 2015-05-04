k, a, b, v = gets.split.collect{|i| i.to_i}
ans = 0
if a <= b/(k-1)*k*v
    puts (a+k*v-1)/(k*v)
    exit
else
    ans += b/(k-1)
    a -= ans*k*v
end
if a <= (b%(k-1)+1)*v
    puts ans+1
    exit
else
    ans += 1
    a -= (b%(k-1)+1)*v
end
puts ans+(a+v-1)/v
