a, b, c, d = gets.split.collect{|i| i.to_i}
a *= c*d
b *= c*d
if a/c > b/d
    p = b/d
    c = a-p*c
    gcd = a.gcd(c)
    print c/gcd, "/", a/gcd, "\n"
else
    p = a/c
    d = b-p*d
    gcd = b.gcd(d)
    print d/gcd, "/", b/gcd, "\n"
end
