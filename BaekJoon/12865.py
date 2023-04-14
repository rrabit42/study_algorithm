n, k = map(int, input().split())

thing = [[0,0]]
d = [[0]*(k+1) for _ in range(n+1)]

for i in range(n):
    thing.append(list(map(int, input().split())))

for i in range(1, n+1):
    for j in range(1, k+1):
        w = thing[i][0]
        v = thing[i][1]

        if j < w:
            d[i][j] = d[i-1][j]
        else:
            d[i][j] = max(d[i-1][j], d[i-1][j-w]+v)

print(d[n][k])

# 시간초과 뜨는 내 풀이.... 왜뜨는지 모르겠음
import sys

input = sys.stdin.readline

# N: 물품의 수, K: 최대 무게
N, K = map(int, input().split())
value = [0 for _ in range(K + 1)]
dp = [0 for _ in range(K+1)]

# w: 각 물건 무게 v: 가치
for _ in range(N):
  w, v = map(int, input().split())
  # value[w] = max(value[w], v) # 각 무게마다 최대 가치 가지고 있기
  dp[w] = value[w] = v

# for i in range(K, 0, -1):
#   minIndex = min(K - i + 1, i)
#   for w, v in enumerate(value[:minIndex]):
#     dp[w] = max(dp[w], dp[w] + value[i])

for i in range(K + 1):
  for j in range(K, i+1, -1):
    dp[j] = max(dp[j - i] + value[i], dp[j])
print(max(dp))
