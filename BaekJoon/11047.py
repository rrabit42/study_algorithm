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
