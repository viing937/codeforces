n = gets.to_i
cnt_7 = n/7
cnt_4 = (n-cnt_7*7)/4
while cnt_7 >= 0 and  cnt_7*7+cnt_4*4 != n
    cnt_7 -= 1
    cnt_4 = (n-cnt_7*7)/4
end
if cnt_7 >= 0 and  cnt_7*7+cnt_4*4 == n
    puts '4'*cnt_4+'7'*cnt_7
else
    puts -1
end
