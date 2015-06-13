n = int(input())
a = [int(i) for i in input().split()]
print(" ".join([str(len([aaa for aaa in a if aaa > aa])+1) for aa in a]))
