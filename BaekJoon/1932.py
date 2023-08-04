import sys
input = sys.stdin.readline

n = int(input())

triangle = [[0]]
for _ in range(n):
  li = [0] + list(map(int, input().split())) + [0]
  triangle.append(li)
dp = [[0 for i in range(n + 1)] for j in range(n + 1)]

dp[1][1] = triangle[1][1]
for i in range(2, n +1):
  for j in range(1, i + 1):
    dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]

print(max(dp[n]))


# 베스트 풀이 - 바로바로 구하네
import sys
input = sys.stdin.readline

N = int(input())
prev = [*map(int, input().split())]

for i in range(1, N):
  nums = [*map(int, input().split())]
  b = [max(prev[j-1], prev[j])+nums[j] for j in range(1, i)] # 1부터 시작해서 j - 1 가능
  prev = [prev[0]+nums[0], *b, prev[-1]+nums[-1]] # 0번, 마지막 인덱스는 따로 계산(그 이전값을 한개 밖에 선택 못하니까)
  # 한줄로는 [prev[0]+nums[0]] + [nums[j] + max(prev[j-1],prev[j]) for j in range(1,i)] + [prev[-1]+nums[-1]]

print(max(prev))

#############################
# 최근에 다시 풀었을 때 내 풀이
import sys

input = sys.stdin.readline
n = int(input())
triangle = []
for i in range(n):
  triangle.append([0] + [j for j in map(int, input().split())])

# bottom-up vs top-down 둘 중에 뭘로 할까
# top-down
for i in range(1, n):
  for j in range(1, len(triangle[i])):
    # (i, j): 현재 자신
    # 이전 행 왼, 오: (i-1, j-1), (i-1, j)
    next = max(triangle[i-1][j-1: j+1])
    triangle[i][j] += next

print(max(triangle[n-1]))

# -> 이거 한줄로 하면
# triangle[i][j] += max(dp[i-1][j-1:j+1])
