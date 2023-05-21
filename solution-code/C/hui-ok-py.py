n = int(input())
a = list(map(int, input().split()))

flag = True
for i in range(1, n):
    if a[i] - a[i-1] != a[1] - a[0]:
        flag = False

if flag:
    print('YES')
    print(*a)
    print('0 ' * n)
else: print('NO')