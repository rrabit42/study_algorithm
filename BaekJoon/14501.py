#####################
# dp top-down
import sys
input = sys.stdin.readline

n = int(input())
schedules = [(*map(int, input().split()),) for _ in range(n)]
dp = [0 for _ in range(16)] # 해당 날짜에 받을 수 있는 최대 금액

for i in range(n-1, -1, -1):
  # i 일에 상담을 해서 퇴사일을 넘긴다면, 상담 X
  if i + schedules[i][0] > n:
    dp[i] = dp[i+1] # 그대로 이어 받음
  # i 일에 상담을 하는 것 vs 상담을 안하는 것
  else:
    dp[i] = max(dp[i + schedules[i][0]] + schedules[i][1],dp[i+1])

print(dp[0])

####################
# dp bottom-down
# greedy 하게 모든 상담 스케줄을 가능한 족족 채우게 되는 경우보다, 며칠 상담을 안하는 경우가 수익이 더 클 수 있음

import sys
input = sys.stdin.readline

n = int(input())
schedules = [(*map(int, input().split()),) for _ in range(n)]
dp = [0 for _ in range(16)] # 해당 날짜에 받을 수 있는 최대 금액

for i in range(n):
  for j in range(i+schedules[i][0], n+1): # 상담 가능한 "모든" 날짜
    if dp[j] < dp[i] + schedules[i][1]:
      dp[j] = dp[i] + schedules[i][1]

print(dp[-1])

#####################
# 틀린 코드
# 연속으로 일 안하고, 건너 뛰어야 더 많은 돈 들어오는 경우도 있음!
import sys
input = sys.stdin.readline

n = int(input())
schedules = [(*map(int, input().split()),) for _ in range(n)]

cost = 0
for i in range(n):
  tc = 0
  while i < n:
    t, p = schedules[i]
    i += t # 다음에 일 가능한 날짜: i
    if i - 1 < n: # i - 1까지 일을 하면 돈 들어옴
      tc += p
  cost = max(cost, tc)

print(cost)
