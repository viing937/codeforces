T = int(input())
for _ in range(T):
    n, k = map(int, input().split())
    if k % 3:
        if n % 3:
            print("Alice")
        else:
            print("Bob")
    else:
        loop = k+1
        idx = n % loop
        if idx == k:
            print("Alice")
        elif idx % 3:
            print("Alice")
        else:
            print("Bob")
