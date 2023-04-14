import sys
input = sys.stdin.readline

n = int(input())

triangle = [[0]]
for _ in range(n):
  li = [0] + list(map(int, input().split())) + [0]
  triangle.append(li)
dp = [[0 for i in range(n + 1)] for j in range(n + 1)]

dp[1][1] = triangle[1][1]
for i in range(2, n +1):
  for j in range(1, i + 1):
    dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]

print(max(dp[n]))


# 베스트 풀이 - 바로바로 구하네
import sys
input = sys.stdin.readline

N = int(input())
prev = [*map(int, input().split())]

for i in range(1, N):
  nums = [*map(int, input().split())]
  b = [max(prev[j-1], prev[j])+nums[j] for j in range(1, i)]
  prev = [prev[0]+nums[0], *b, prev[-1]+nums[-1]]

print(max(prev))
