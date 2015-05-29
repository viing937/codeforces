from collections import Counter
n, m = [int(i) for i in input().split()]
markers = []
for i in range(n):
    markers.append(input())
caps = []
for i in range(m):
    caps.append(input())
markers = Counter(markers)
caps = Counter(caps)
v = len(list((markers&caps).elements()))
markers, caps = markers-caps, caps-markers
markers = Counter([marker.split()[1] for marker in markers.elements()])
caps = Counter([cap.split()[1] for cap in caps.elements()])
u = len(list((markers&caps).elements()))
print(u+v, v)
