import sys
MAX = 10001
input = sys.stdin.readline

n, k = map(int, input().split())

coins = set([int(input()) for _ in range(n)])

# 아 금액 별로 dp...
dp = [MAX] * (k + 1)
dp[0] = 0

for coin in coins:
  for i in range(coin, k+1):
    dp[i] = min(dp[i], dp[i-coin] + 1)
if dp[k] == MAX:
  print(-1)
else:
  print(dp[k])


# 예상되는 반례: 이렇게 풀면 반드시 연속적으로 coin을 확인하기 때문에 최적합이 안나올 수 있음
# ex) a,b,c,d,e 코인이 있으면 a,c,e 코인만 쓰면 최적합인데 내 코드는 a,b,c,d,e를 순차적으로 다 확인하고 사용함...

# import sys
# MAX = 10001
# input = sys.stdin.readline

# n, k = map(int, input().split())

# coins = sorted(set([int(input()) for _ in range(n)]),reverse=True)

# s = MAX

# def sol(coin, num, value):
#   if value >= coin:
#     p = value // coin # 몫
#     num += p # 동전 개수
#     v = value - p * coin # 남은 금액
#     return num, v
#   return num, value
  
# for i, coin in enumerate(coins):
#   num, value = sol(coin, 0, k)
#   for c in coins[i+1:]:
#     num, value = sol(c, num, value)

#   if value == 0 and s > num:
#     s = num

# if s == MAX:
#   print(-1)
# else:
#   print(s)

