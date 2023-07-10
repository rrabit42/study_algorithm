import sys
input = sys.stdin.readline

n, m = map(int, input().split())

result = []
def sol(start):
  if len(result) == m:
    print(*result)
    return

  # 비내림차순으로 들어가야함
  for i in range(start, n + 1):
    result.append(i)
    sol(i)
    result.pop()

sol(1)

#####################
# itertools 쓰는 방법 (이런 함수도 있었군,,)

import sys
from itertools import combinations_with_replacement as combwr

n, m = map(int, input().split())
arr = range(1, n + 1)
for i in combwr(arr, m):
  print(*i)
