n = int(input())
a = list(map(int, input().split()))
p = [0] * n
res = [0] * n

for i in range(n):
    a[i] -= 1
    p[a[i]] = i

for i in range(n):
    j = p[i]
    dist = i - j if i > j else j - i
    if i == j: continue
    a[i], a[j] = a[j], a[i]
    p[a[i]] = i
    p[a[j]] = j
    res[a[i]] += dist
    res[a[j]] += dist

print(*res)