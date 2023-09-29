import sys
input = sys.stdin.readline

DIV = 1000000009

dp = [1, 2, 4, 7]
for _ in range(int(input())):
  # 방법의 총 수 dp, 순서 바꾸는 것도 포함이네..
  n = int(input())

  for i in range(len(dp), n):
    # 알아서 1, 2, 3이 각각 들어갈 것 -> 겹치는게 없음
    dp.append((dp[i-1] + dp[i-2] + dp[i-3]) % DIV)

  print(dp[n-1])
