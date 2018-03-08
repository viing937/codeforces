n, m = map(int, input().split())
ipToName = {}
for _ in range(n):
    name, ip = input().split()
    ipToName[ip] = name
for _ in range(m):
    command, ip = input().split()
    print(command, ip, '#'+ipToName[ip[:-1]])
