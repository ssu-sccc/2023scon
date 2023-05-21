n = int(input())
a = list(map(int, input().split()))

sz = n * 61 + 2
c = [0] * (sz*2)
s = [0] * sz
p = 1

def insert(v):
    global p
    x = 1
    s[x] += 1
    for i in range(60):
        key = v >> i & 1
        idx = x << 1 | key
        if c[idx] == 0:
            p += 1
            c[idx] = p
        x = c[idx]
        s[x] += 1

def dfs(node, take):
    if node == 0 or s[node] == take: return 0
    if c[node<<1] == 0 and c[node<<1|1] == 0: return s[node] - take
    l, r = c[node<<1], c[node<<1|1]
    if l == 0: return dfs(r, take+1) + 1
    if r == 0: return dfs(l, take+1) + 1
    return max(dfs(l, max(0,take-s[r])+1), dfs(r, max(0,take-s[l])+1)) + 1

for i in a: insert(i)
print(dfs(1, 0))
