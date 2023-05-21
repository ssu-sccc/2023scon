import copy

n, k, x = map(int, input().split())
g = [[] for _ in range(n)]
d = [[[] for _ in range((x+1)**k)] for _ in range(n)]

for i in range(n):
    now = list(map(int, input().split()))[1:]
    for j in now: g[i].append(j - 1)

a = list(map(int, input().split()))
o = [0] * n
for i in range(n): o[i] = i
o.sort(key = lambda x: -a[x])

def encode(v):
    res = 0
    for i in v: res = res * (x + 1) + i
    return res

def decode(v):
    res = [0] * k
    for i in range(k):
        res[k-i-1] = v % (x + 1)
        v //= x + 1
    return res

for i in g[o[0]]:
    a = [0] * k
    b = [-1] * n
    a[i] = 1
    b[o[0]] = i
    d[0][encode(a)] = b

for i in range(1, n):
    match = False
    for gr in range((x+1)**k):
        if not d[i-1][gr]: continue
        group = decode(gr)
        assign = d[i-1][gr]
        for j in g[o[i]]:
            if group[j] == x: continue
            a = copy.deepcopy(group)
            b = copy.deepcopy(assign)
            a[j] += 1
            b[o[i]] = j
            id = encode(a)
            if not d[i][id]:
                d[i][id] = b
                match = True
    if not match: d[i] = d[i-1]

res = []
for i in d[n-1]:
    if i: res = i

for i in range(k):
    now = []
    for j in range(n):
        if res[j] == i: now.append(j+1)
    print(len(now), *now)
    