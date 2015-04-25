n, m = gets.split.collect{|i| i.to_i}
a = Array.new(3,0)
gets.split.each{|i| a[i.to_i+1]+=1}
(1..m).each do
    l, r = gets.split.collect{|i| i.to_i}
    if (r-l+1).odd?
        puts 0
    elsif a[0] < (r-l+1)/2 or a[2] < (r-l+1)/2
        puts 0
    else
        puts 1
    end
end
