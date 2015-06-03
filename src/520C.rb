n = gets.to_i
s = gets.chomp
m = [s.count("A"), s.count("C"), s.count("T"), s.count("G")]
cntmax = m.max
cnt = 0
m.each{|mm| cnt += 1 if mm == cntmax}
puts (cnt**n)%(10**9+7)
