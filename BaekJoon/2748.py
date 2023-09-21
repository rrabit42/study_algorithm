import sys
input = sys.stdin.readline

n = int(input())

dp = [0] * (n+2)
dp[0], dp[1], dp[2] = 0, 1, 1

for i in range(2, n+1):
  dp[i] = dp[i-1] + dp[i-2]

print(dp[n])

####################
# 와 이건 많이 봤는데도 난 아직 생각 못해내네...
a,b=0,1
for _ in range(int(input())-1):
    a,b=b,a+b
print(b)
