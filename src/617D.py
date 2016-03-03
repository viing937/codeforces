def f(a, b, c):
    return (x[a] == x[b] and (y[c] <= min(y[a], y[b]) or y[c] >= max(y[a], y[b]))) or\
           (y[a] == y[b] and (x[c] <= min(x[a], x[b]) or x[c] >= max(x[a], x[b])))

x, y = list(zip(*[list(map(int, input().split(' '))) for i in range(3)]))

if len(set(x)) == 1 or len(set(y)) == 1:
    print(1)
elif f(0, 1, 2) or f(0, 2, 1) or f(1, 0, 2) or\
     f(2, 1, 0) or f(2, 0, 1) or f(1, 2, 0):
    print(2)
else:
    print(3)
