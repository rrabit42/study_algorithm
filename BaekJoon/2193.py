import sys
input = sys.stdin.readline

# 이친수
n = int(input())

# 그 전 개수에서 0과 1을 알아서 더 놓으면 됨
# 다만 1로 끝나면 그 뒤는 무조건 0이라서, 끝나는 수에 따라 구분해야함
# 즉 n = (n-1에서 0으로 끝나는 개수)*2 + (n-1에서 1로 끝나는 개수)
dp = [[0,0] for _ in range(90+1)]
dp[1], dp[2], dp[3] = [0,1], [1,0], [1,1]

for i in range(4, n+1):
  dp[i] = [dp[i-1][0] + dp[i-1][1], dp[i-1][0]]

print(sum(dp[n]))

#################################
# 대체 다들... 알고리즘 잘하는 사람은 왜이렇게 많을까?
# 저장해 두지 않고 그때 그때 계산!

n = int(input())
a = 0; b = 1 # 0으로 끝나는 개수, 1로 끝나는 개수
for i in range(2, n + 1):
    a, b = b, a + b
print(b)
