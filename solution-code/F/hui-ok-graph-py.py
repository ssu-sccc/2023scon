n, m = map(int, input().split())
c = [0] * n
g = [[0 for _ in range(n)] for _ in range(n)]
res = 0

for i in range(m):
    u, v = map(int, input().split())
    g[u-1][v-1] = g[v-1][u-1] = 1

def dfs(v):
    c[v] = 1
    for i in range(n):
        if g[v][i] == 1 and c[i] == 0: dfs(i)

for i in range(n):
    if c[i] == 0:
        dfs(i)
        res += 1

print(res - 1)