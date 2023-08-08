import sys
input = sys.stdin.readline

n = int(input())

# 바로 왼쪽 숫자와의 경우의 수만 따지면 됨
# 0, 9만 경우의 수가 1개고 나머지는 모두 2개씩
dp = [[0]*10 for _ in range(n+1)] # n자리 수일 때 계단수 개수
for i in range(1, 10): # i로 끝나는 숫자
  dp[1][i] = 1

for i in range(2, n+1):
  for j in range(10): # 그 다음에 올 숫자 j
    if j == 0:
      dp[i][j] = dp[i-1][1]
    elif j == 9:
      dp[i][j] = dp[i-1][8]
    else:
      dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]

print(sum(dp[n])%1000000000)
###########
# 간단하게 표현
import sys
input = sys.stdin.readline

n = int(input())
dp = [0, *[1]*9] # 1의 경우

for i in range(n-1):
  dp = [dp[1], *[dp[i-1] + dp[i+1] for i in range(1, 9)], dp[8]]

print(sum(dp)%1000000000)

##########
# 처음 잘못 생각함
import sys
input = sys.stdin.readline

n = int(input())

dp = [0 for _ in range(101)] # n자리 수일 때 계단수 개수
dp[1], dp[2] = 9, 17

# 바로 왼쪽 숫자와의 경우의 수만 따지면 됨
# 0, 9만 경우의 수가 1개고 나머지는 모두 2개씩
# 계산식으로는 정리할 수 없음.. 0, 9 경우는 개수가 다른 애들이랑 달라지니까
for i in range(3, n+1):
  dp[i] = (dp[i-1] - 2)

print(dp[n]%1000000000)
