n = int(input())
s = input()
res = 0

def f(idx):
    global res
    if idx == n:
        res += 1
        return
    f(idx + 1)
    if idx + 7 < n and s[idx:idx+8] == 'longlong':
        f(idx + 8)

f(0)
print(res)