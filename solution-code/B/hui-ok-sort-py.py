a = []

for i in range(3):
    p, y, s = input().split()
    a.append((int(p), int(y), s))

a.sort(key = lambda x: x[1])
for i in range(3):
    print(a[i][1] % 100, end='')
print()

a.sort(key = lambda x: -x[0])
for i in range(3):
    print(a[i][2][0], end='')
print()