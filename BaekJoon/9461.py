import sys
input = sys.stdin.readline

# 파도반 수열
# P(0) = P(1) = P(2) = 1
# P(n) = P(n-2) + P(n-3) (n>=3)

MAX = 100 + 1
dp = [1] * MAX
for i in range(3, MAX):
  dp[i] = dp[i-2] + dp[i-3]

T = int(input())
for _ in range(T):
  n = int(input())-1
  print(dp[n])
