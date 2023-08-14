######################################
# 2023.04.25
import sys

input = sys.stdin.readline

n, k = map(int, input().split())
coins = []
for _ in range(n):
  coins.append(int(input()))

left = k
count = 0
coins.sort(reverse=True) # 그냥 for k in range(t-1, -1, -1) 하면 sort 안해도 됨
for coin in coins: # 당연하게 큰 수부터 나누면 최솟값이 나옴
  p = left // coin
  count += p
  left = left % coin
  
print(count)
==========================================
# 2023.08.14
# 오 발전했는데ㅋㅋㅋㅋ

import sys
input = sys.stdin.readline

n, k = map(int, input().split())
a = [int(input()) for _ in range(n)] # 오름차순

num = 0
for i in range(n-1, -1, -1):
  if k >= a[i]:
    p, k = divmod(k, a[i])
    num += p

print(num)
