a, b = map(int, input().split(" "))
step = 1
while True:
    if a < step:
        print("Vladik")
        exit()
    a -= step
    if b < step+1:
        print("Valera")
        exit()
    b -= step+1
    step += 2
