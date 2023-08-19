#####################
# 2xn 타일링을 제대로 이해했어야 했음...
# 수학적 식 세우는 연습 하자!

import sys
input = sys.stdin.readline

n = int(input())

# 2xn을 1x2, 2x1, 2x2 로 채우는 방법
dp = [0 for _ in range(n+1)]
dp[1], dp[2] = 1, 3

for i in range(3, n+1):
  # dp[i-1]에서 1x2가 하나 늘어난 개수 +
  # dp[i-2]에서 2x2의 경우의 수 2개(2x2 or 2x1 * 2) -> 위에꺼에 없는 경우로 알아서 채워짐
  dp[i] = dp[i-1] + dp[i-2] * 2
  
print(dp[n])
