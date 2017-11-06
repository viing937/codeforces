n, k = map(int, input().split(" "))
count = [0] * 101
for i in range(n):
    count[len(input())] += 1
length = len(input())
minTry, maxTry = sum(count[:length])+1, sum(count[:length+1])
print(minTry + (minTry-1)//k*5, maxTry + (maxTry-1)//k*5)
