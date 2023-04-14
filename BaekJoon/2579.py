import sys

input = sys.stdin.readline
n = int(input())

stairs = [0]
for _ in range(n):
  stairs.append(int(input()))

dp = [0 for _ in range(n + 1)]

dp[1] = stairs[1]
if n >= 2: # index 에러
  dp[2] = stairs[1] + stairs[2]
for i in range(3, n + 1):
  dp[i] = max(dp[i-2], dp[i-3] + stairs[i - 1]) + stairs[i]

print(dp[n])

# 미리 그냥 배열을 선언하는 것도 좋을듯. 300개 뿐이니..
import sys
input = sys.stdin.readline
n = int(input())
dp = [0]*301
scores = [0]*301

for i in range(n):
    scores[i+1] = int(input())

dp[1] = scores[1]
dp[2] = dp[1] + scores[2]

for i in range(3, n+1):
    dp[i] = max(dp[i-2]+scores[i],dp[i-3]+scores[i-1]+scores[i])

print(dp[n])
