import sys

def prime_filter(N, K):
  is_prime = [1 for i in range(N + 1)] # [1] * (N+1)
  cnt = 0
  for i in range(2, N + 1):
        for j in range(i, N + 1, i):
            if is_prime[j]:
              is_prime[j] = 0
              cnt += 1
              if cnt == K:
                  print(j)
                  return
            
input = sys.stdin.readline
N, K = map(int, input().split())
prime_filter(N, K)

# 풀이
nums = [True] * (N + 1)
for i in range(2, len(nums) + 1):
    for j in range(i, N+1, i):
        if nums[j] == True:
            nums[j] = False
            cnt = cnt + 1
            if cnt == K:
                print(j)
                break
