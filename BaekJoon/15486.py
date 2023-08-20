# 퇴사1과 다른건, 그때는 경우의 수가 작아서 dfs로도 풀 수 있었다는 것
# 근데 애초가 dp로 풀었기에 풀이가 똑같음...ㅎㅎ

# top-down
import sys
input = sys.stdin.readline

n = int(input())
s = [(*map(int, input().split()),) for _ in range(n)]
dp = [0 for _ in range(n+1)] # n일 차 때 최대 이익 -> 0일 때 최대 이익이 되도록 만들어 나감

# 거꾸로 생각하기
for i in range(n-1, -1, -1):
  if i + s[i][0] <= n:
    # 그대로 이어 받기 vs 오늘 상담 진행하기
    dp[i] = max(dp[i+s[i][0]] + s[i][1], dp[i+1])
  else:
    dp[i] = dp[i+1]

print(dp[0])

########################
# 이렇게 bottom-up 하면 시간 초과...
import sys
input = sys.stdin.readline

n = int(input())
s = [(*map(int, input().split()),) for _ in range(n)]
dp = [0 for _ in range(n+1)] # n일 차 때 최대 이익

for i, (t, p) in enumerate(s):
  for j in range(i+t, n+1):
    if dp[j] <= dp[i] + p:
      dp[j] = dp[i] + p

print(dp)
  
###########
# bottom-up 시간 초과 안남!!!!!!!!!
import sys

input = sys.stdin.readline

def solution():
    N = int(input())
    dp = [0]*(N+1)
    for i in range(N):
        T, P = map(int, input().split())
        if dp[i] > dp[i+1]:
            dp[i+1] = dp[i]
        if i+T < N+1 and dp[i]+P > dp[i+T]:
            dp[i+T] = dp[i]+P
    print(dp[-1])

solution()
