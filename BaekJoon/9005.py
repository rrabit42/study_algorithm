import sys

input = sys.stdin.readline
t = int(input())

dp = [0 for _ in range(11)] # 합으로 나타내는 방법 개수
dp[1], dp[2], dp[3] = 1, 2, 4

def sol(num):
  if num <= 0:
    return 0
  elif dp[num] != 0:
    return dp[num]
    
  dp[num] = sol(num-3) + sol(num - 2) + sol(num - 1) # 3이 존재하는 합의 경우의 수 sol(num-3), 2가 존재하는 합의 경우의 수 sol(num-2), ...
  return dp[num]

for _ in range(t):
  n = int(input())
  sol(n)
  print(dp[n])
  
