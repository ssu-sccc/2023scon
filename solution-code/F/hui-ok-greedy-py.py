n, m = map(int, input().split())
g = [[0 for _ in range(n)] for _ in range(n)]
res = 0

for i in range(m):
    u, v = map(int, input().split())
    g[u-1][v-1] = 1

def go(c):
    global res
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                if g[i][j] + g[i][k] + g[j][k] + c == 2:
                    g[i][j] = g[i][k] = g[j][k] = 1
                    res += c
                    return True
    return False

while go(0) or go(1):
    pass

print(res)