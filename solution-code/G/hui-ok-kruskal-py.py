n, m, s = map(int, input().split())
p, r = [0] * n, [0] * n
e = []
res = 0

def find(v):
    while v != p[v]: v, p[v] = p[v], p[p[v]]
    return v

def merge(u, v):
    u = find(u)
    v = find(v)
    if u == v: return False
    if r[u] > r[v]: u, v = v, u
    p[u] = v
    if r[u] == r[v]: r[v] += 1
    return True

for i in range(m):
    u, v, w = map(int, input().split())
    e.append((w, u-1, v-1))

for i in range(n): p[i] = i
e.sort()

for w, u, v in e:
    if merge(u, v): res += w

print(res)