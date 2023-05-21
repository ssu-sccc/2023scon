n, m, s = map(int, input().split())
g = [[1e9 for _ in range(n)] for _ in range(n)]
c = [1e9 for _ in range(n)]
f = [False for _ in range(n)]

for _ in range(m):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    g[u][v] = min(g[u][v], w)
    g[v][u] = min(g[v][u], w)

f[0] = True
for i in range(1, n): c[i] = g[0][i]

r = 0
for _ in range(n-1):
    v = 0
    for i in range(n):
        if c[v] > c[i]: v = i
    r += c[v]
    c[v] = 1e9
    f[v] = 1
    for i in range(n):
        if not f[i]: c[i] = min(c[i], g[v][i])

print(r)