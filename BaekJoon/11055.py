# n이 최대 1000 이고 시간 제한이 1초이므로, O(n^2) 시간의 알고리즘을 설계하면 해결할 수 있음

import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

dp = [0] * n  # 각 인덱스 위치에 가장 큰 증가 부분 수열의 합!!!!!!*** 합 자체를 dp 로 놓으면 된다!!!!
dp[0] = arr[0]

# 반복문을 통해 각 인덱스 위치에 가장 큰 증가 부분 수열의 합을 구한다
for i in range(1, n):
  for j in range(i):  # 현재 인덱스 값과 이전 인덱스의 값 비교
    # 현재 수가 이전 수보다 크다면
    # 현재 인덱스 위치에 가장 큰 부분 수열의 합과 이전 인덱스 위치에 가장 큰 부분 수열의 합 + 현재 수를 비교
    if arr[i] > arr[j]:
      dp[i] = max(dp[i], dp[j] + arr[i])
    # 이전 수가 더 크거나 같다면, 현재 인덱스 위치에 가장 큰 부분 수열의 합과 현재 수 비교
    else:
      dp[i] = max(dp[i], arr[i]) # 사실 이 부분은 의미 없음.. dp[i]는 0으로 초기화 되어 있는뎁쇼, 수열 끊기면 자기자신만 해당됨...

print(max(dp))

################################################
# 위 코드 보완
import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
dp = arr[:] # arr로 초기화하면 else문 필요 없음!

for i in range(1, n):
  for j in range(i):
    if arr[i] > arr[j]:
      dp[i] = max(dp[i], dp[j] + arr[i])
      
print(max(dp))
###################################
# 와우...
# index 위치를 이용해서 현재 이전에 나온, 작은 숫자들의 합을 알 수 있음 -> 큰 증가하는 부분 수열의 합....
input()
dp = [0] * 1001
for i in map(int, input().split()):
    dp[i] = max(dp[:i]) + i # index 위치를 이용해서 증가하는 부분 수열의 합을 구하는것,, 와,,,
    print(i, dp)
print(max(dp))

