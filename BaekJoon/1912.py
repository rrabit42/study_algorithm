import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

# 연속된 수의 합에서 가장 큰 합
# dp: 현재 위치에서 연속합의 최대 합

# 이전 연속합을 더하거나, 더하지 않고 지금 숫자가 연속합의 첫 숫자가 되느냐!
# dp[n] = max(dp[n-1] + arr[n], arr[n])

dp = [-1000 for _ in range(n+1)]
dp[0] = arr[0]
for i in range(1, n):
  dp[i] = max(dp[i-1]+arr[i], arr[i]) # 단순하게 dp[i-1]가 음수가 아니면 더해주는 것!

print(max(dp))

################################
# 위 주석을 반영한 풀이
n = int(input())
numbers = list(map(int, input().split()))

for i in range(1, n):
  if numbers[i-1] > 0:
    numbers[i] += numbers[i-1]

result = max(numbers)

print(result)
