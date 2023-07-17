import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = sorted(set(map(int, input().split())))

result = []
def sol(start):
  if len(result) == m:
    print(*result)
    return

  for i in range(start, len(arr)):
    result.append(arr[i])
    sol(i)
    result.pop()

sol(0)

########################
# itertools 사용

import sys
from itertools import combinations_with_replacement
input = sys.stdin.readline

n, m = map(int, input().split())
arr = sorted(set(map(int, input().split())))

for i in combinations_with_replacement(arr, m):
  print(*i)
