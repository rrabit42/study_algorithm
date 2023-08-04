import sys

input = sys.stdin.readline
n, m = map(int, input().split())
arr = list(map(int, input().split()))

# 누적합 구하기
# 구간은 1부터 시작하니까 index 맞춰주기
dp = [0] + arr.copy()
for i in range(1, n+1):
  dp[i] += dp[i-1]

# 누적합 가지고 있고, 그만큼 차를 빼면 됨
for _ in range(m):
  i, j = map(int, input().split())
  if i == j:
    print(arr[i-1]) # arr는 index 0 부터 시작이므로
  else:
    print(dp[j] - dp[i-1])

########
# 어차피 차가 그 인덱스에 있던 숫자를 의미하므로 굳이 if문 필요 없음!

import sys

input = sys.stdin.readline
n, m = map(int, input().split())
arr = list(map(int, input().split()))

# 누적합 구하기
# 구간은 1부터 시작하니까 index 맞춰주기
dp = [0] + arr.copy()
for i in range(1, n+1):
  dp[i] += dp[i-1]

# 누적합 가지고 있고, 그만큼 차를 빼면 됨
for _ in range(m):
  i, j = map(int, input().split())
  if i == j:
    print(dp[j] - dp[i-1])

###################
# itertools 쓰기
# accmulate 라는 함수도 있다니..ㅋ

import sys
from itertools import accumulate

lines = map(bytes.split, sys.stdin.buffer.read().splitlines())
n, m = next(lines)
sums = list(accumulate(map(int, next(lines)), initial=0))
sys.stdout.write('\n'.join(str(sums[int(j)] - sums[int(i) - 1]) for i, j in lines))
