n = int(input())
bin_n = bin(n)[2:]

l = len(bin_n)
ans = [str(l-i) for i in range(l) if bin_n[i] == '1']
print(' '.join(ans))
