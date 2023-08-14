# 재귀랑 dp를 헷갈리지 말자!!!
import sys
input = sys.stdin.readline

dp = [[0,0] for _ in range(41)] # 0 ~40
dp[0], dp[1], dp[2], dp[3] = [1,0], [0,1], [1,1], [1,2]

t = int(input())
for _ in range(t):
  n = int(input())
  for i in range(4, n+1):
    z1, o1 = dp[i-1]
    z2, o2 = dp[i-2]
    dp[i] = [z1+z2, o1+o2]
  print(*dp[n])

#############################
# 테스트 케이스 받기도 전에 미리 만들어놓고 출력
# 그리고 dp를 만드는 방식도 특이하다. 다른 규칙인듯 한데 수학적 근거를 모르겠음
# 아! 알았다. 0의 횟수, 1의 횟수도 각각 피보나치 수열의 규칙을 띰!!! 0보다 1이 한칸 더 앞선 피보나치 수열임!!!
# 그래서 자동적으로 0과 1횟수의 합이 f(n-1)+f(n-2)의 형태를 띄어서 1의 횟수에 저렇게 sum()으로 들어가는거고
# 0의 횟수의 다음 자리는 그 전 1횟수 자리이므로(1이 0개수보다 한칸 앞서므로)~~~~ 예아

from sys import stdin
input = stdin.readline

t = int(input())
arr = [0] * 41
arr[0] = [1, 0]; arr[1] = [0, 1]
for i in range(2, 41):
    arr[i] = [arr[i-1][1],sum(arr[i-1])]
for i in range(t):
    N = int(input())
    print(*arr[N])

############################
# 시간 초과 뜬 첫 코드
import sys
input = sys.stdin.readline

zero, one = 0, 0

def fibo(n):
  global zero, one
  if n == 0:
    zero += 1
    return
  elif n == 1:
    one += 1
    return
  fibo(n-1)
  fibo(n-2)
  return

t = int(input())
for _ in range(t):
  n = int(input())
  zero, one = 0, 0
  fibo(n)
  print(zero, one)

###########################
# 다른 시간초과
# dp 라고 푼줄 알았는데 걍 재귀였잖아?? 다시 dp로 제대로 풀자!

import sys
input = sys.stdin.readline

dp = [[0,0] for _ in range(41)] # 0 ~40
dp[0], dp[1] = [1,0], [0,1]

def fibo(n):
  if dp[n] != [0,0]:
    return dp[n]
  z1, o1 = fibo(n-1)
  z2, o2 = fibo(n-2)
  return [z1+z2, o1+o2]

t = int(input())
for _ in range(t):
  n = int(input())
  zero, one = fibo(n)
  print(zero, one)
