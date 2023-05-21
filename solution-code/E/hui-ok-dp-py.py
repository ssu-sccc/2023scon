n = int(input())
s = input()

dp = [0] * 22
dp[0] = dp[1] = 1
for i in range(2, 22):
    dp[i] = dp[i-1] + dp[i-2]

now, res, idx = 0, 1, 0

while idx < n:
    if idx + 3 < n and s[idx:idx+4] == "long":
        now += 1
        idx += 4
    else:
        res *= dp[now]
        now = 0
        idx += 1

print(res * dp[now])