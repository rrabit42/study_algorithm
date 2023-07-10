import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(int, input().split()))

# 배열 정렬
arr.sort()

# n개의 자연수 중에서 m개 고름
result = []
def sol(idx):
  if len(result) == m:
    print(*result)
    return

  for i in range(0, n):
    if arr[i] not in result:
      result.append(arr[i])
      sol(i + 1)
      result.pop()

sol(0)
###############################
# itertools 사용
import sys
from itertools import permutations
input = sys.stdin.readline

n, m = map(int, input().split())
arr = sorted(list(map(int, input().split())))

for i in permutations(arr, m):
  print(*i)

