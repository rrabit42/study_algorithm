import sys

input = sys.stdin.readline
n = int(input())
nums = list(map(int, input().split()))
dp = [1 for _ in range(n)]

# dp[0] = 1 이렇게 했었는데, dp[0]이 제일 작다는 보장도 없고, 모든 원소는 적어도 길이가 1인 부분집합이니까
# 1로 초기화 해줬어야 함!
for i in range(1, n):
  for j in range(i): # enumerate 써도 괜찮았을듯!
    if nums[i] > nums[j]:
      dp[i] = max(dp[j] + 1, dp[i])

# 마찬가지로 맨 마지막이 제일 길지 않으므로 Max 해줘야함!
print(max(dp))
