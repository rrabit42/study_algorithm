import sys
input = sys.stdin.readline

n = int(input())
# memoization
dp = [0, 1]

for i in range(2, n + 1):
  dp.append((dp[i-1] + dp[i - 2]) % 1000000007)

print(dp[n])
