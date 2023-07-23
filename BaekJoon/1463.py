import sys

input = sys.stdin.readline
n = int(input())

# bottom up dp
dp = [0 for i in range(n+1)]

# 연산의 최솟값!!
result = 0
for i in range (2, n+1):
  dp[i] = dp[i-1] + 1
  if i% 2 == 0:
    dp[i] = min(dp[i], dp[i//2] + 1)
  if i % 3 == 0:
    dp[i] = min(dp[i], dp[i//3] + 1)

print(dp[n])

######################
# 와우
from sys import stdin
d = {1: 0, 2: 1}

def sol(n: int) -> int:
    if n in d:
        return d[n]
    t = 1 + min(sol(n // 3) + n % 3, sol(n // 2) + n % 2)
    d[n] = t
    return t

print(sol(int(stdin.readline())))

###############
# 초반에 그냥 풀었을 때, 이렇게는 최솟값을 구할 수도 없을 뿐더러, 시간도 오래 걸림

import sys

input = sys.stdin.readline
n = int(input())

result = 0
def cal(num):
  global result
  
  if num == 1:
    return
  elif num % 3 == 0:
    result += 1
    cal(num//3)
  elif num % 2 == 0:
    result += 1
    cal(num//2)
  else:
    result += 1
    cal(num - 1)

cal(n)
print(result)
