import sys
input = sys.stdin.readline

n = int(input())
# memoization
dp = [0 for _ in range(n+1)]

def fibo(n):
  if n <= 1:
    return n
  if dp[n]:
    return dp[n]
  dp[n] = fibo(n-1) + fibo(n-2)
  return dp[n]

print(fibo(n))

# 와우
n = int(input())
dp = [0,1]

for i in range(1,n):
    dp.append(dp[i]+dp[i-1]) #  dp.append(dp[i-2]+dp[i-1])
print(dp[n])
