import sys
input = sys.stdin.readline

n = int(input())
dp = [0 for _ in range(n+1)] # n 만드는데 사용한 연산의 최솟값
dp[1] = 0
logs = [i for i in range(n+1)]
logs[1] = 0

for i in range(2, n+1):
  dp[i] = dp[i-1] + 1 # 1 뺀거랑 비교
  logs[i] = i - 1
  
  if i % 3 == 0:
    if dp[i//3] + 1 <= dp[i]: # 여기에 =가 있어야함!!
      dp[i] = dp[i//3] + 1
      logs[i] = i // 3
      
  if i % 2 == 0:
    if dp[i//2] + 1 <= dp[i]:
      dp[i] = dp[i//2] + 1
      logs[i] = i //2

print(dp[n])
print(n, end=" ")
t = n
while logs[t] != 0:
  print(logs[t], end = " ")
  t = logs[t]

#####################
# 왜 틀렸는지 모르겠는 코드
import sys
input = sys.stdin.readline

n = int(input())
dp = [0 for _ in range(3+n)] # n 만드는데 사용한 연산의 최솟값
dp[1], dp[2], dp[3] = 0, 1, 1
logs = [[i, 1] for i in range(n+1)] # 거쳐온 숫자, index로 넣으면 될듯

# 6의 배수일 때는 logs가 이상하게 나옴!
for i in range(4, n+1):
  dp[i] = dp[i-1] + 1 # 1 뺀거랑 비교
  if i % 3 == 0:
    if dp[i//3] + 1 <= dp[i]: # 여기에 =가 있어야함!!
      logs[i].extend(logs[i//3])
      dp[i] = dp[i//3] + 1
      continue
  if i % 2 == 0:
    if dp[i//2] + 1 <= dp[i]:
      logs[i].extend(logs[i//2])
      dp[i] = dp[i//2] + 1
      continue
  logs[i].extend(logs[i-1])  # 두 경우에 해당 안되면 무조건 이게 들어가야함!

print(dp[n])
print(*sorted(set(logs[n]), reverse=True))
