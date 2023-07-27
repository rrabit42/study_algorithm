import sys

input = sys.stdin.readline
n = int(input())
# 2 x n
# 2로 고정되어 있으니 이걸 기준으로 계산하기
dp = [0 for _ in range(1000 + 1)]
print(dp)
dp[1], dp[2] = 1, 2 # index 에러 발생!

# 기존에 dp[i-2], dp[i-1] 을 이용한 방법이 맞았음!!!
for i in range(3, n + 1):
  dp[i] = (dp[i-2]+ dp[i-1]) % 10007 # 중복 빼면 단순히 더하는 것

# result % 10007
print(dp[n])

###############################
# 와.. ㅋㅋㅋㅋㅋ 하긴 cache로 저장해 놓을 필요가 없지
a=b=1
for _ in range(int(input())):
    a,b=b,a+b
print(a%10007)
