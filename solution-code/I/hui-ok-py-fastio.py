import sys
input = sys.stdin.readline

n, q = map(int, input().split())
p, s, r = [0] * (2*n), [0] * (2*n), [0] * (2*n)

res = 0

for i in range(n*2):
    p[i] = i
    s[i] = i % 2

def find(v):
    while v != p[v]: v, p[v] = p[v], p[p[v]]
    return v

def merge(u, v):
    global res
    u = find(u)
    v = find(v)
    if u == v: return
    if find(u^1) == u: res -= s[u]
    if find(v^1) == v: res -= s[v]
    if r[u] > r[v]: u, v = v, u
    p[u] = v
    s[v] += s[u]
    if r[u] == r[v]: r[v] += 1
    if find(v^1) == v: res += s[v]

for i in range(q):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    merge(u*2, v*2+1)
    merge(v*2, u*2+1)
    print(res)