n = int(input())
cnt = {'polycarp': 1}
for i in range(n):
    arr = input().split()
    name1 = arr[0].lower()
    name2 = arr[2].lower()
    cnt[name1] = cnt[name2]+1
print(max(cnt.values()))
