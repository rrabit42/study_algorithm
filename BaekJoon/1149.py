import sys

## dp로 다시 풀기!!
input = sys.stdin.readline
n = int(input())
dp = [[i for i in map(int, input().split())] for _ in range(n)]

# dp = [[1000 * n for _ in range(n)] for _ in range(n)]
# dp[0] = cost[0]

for r in range(1, n):
  for c in range(3):
    t = dp[r-1][:c]
    if c + 1 < n:
      t += dp[r-1][c+1:]
    dp[r][c] += min(t)

print(min(dp[n-1]))

#################
# r, g, b를 이렇게 분리

import sys
input = sys.stdin.readline

N = int(input())
RGB = [0] * 3 # dp 같은 존재
for _ in range(N):
    r, g, b = map(int, input().split())
    RGB = [r + min(RGB[1], RGB[2]), g + min(RGB[0], RGB[2]), b + min(RGB[0], RGB[1])] # 배열
print(min(RGB))

################
# 시간초과 난 내 코드
# 생각해보니 이건 재귀로 푼거잖아?!

import sys

input = sys.stdin.readline
n = int(input())
cost = [[i for i in map(int, input().split())] for _ in range(n)]

# color = {
#   '0': 'R',
#   '1': 'G',
#   '2': 'B',
# }

result = 1000 * n
def dp(colors):
  global result
  
  if len(colors) == n:
    s = 0
    for i, c in enumerate(colors):
      s += cost[i][c]
    result = min(result, s)
    return

  top = colors[-1]
  for i in (set([0, 1, 2]) - set([top])):
    colors.append(i)
    dp(colors)
    colors.pop()

for x in range(3):
  dp([x])

print(result)
