import sys
from itertools import *
input = sys.stdin.readline

n, m = map(int, input().split())
arr = sorted(list(map(int, input().split())))

arr.sort()
result = []
def sol(start):
  if len(result) == m:
    print(*result)
    return

  for i in range(start, n):
    result.append(arr[i])
    sol(i)
    result.pop()

sol(0)

##################################
# itertools 사용

import sys
from itertools import combinations_with_replacement
input = sys.stdin.readline

n, m = map(int, input().split())
arr = sorted(list(map(int, input().split())))

arr.sort()

for i in combinations_with_replacement(arr, m):
  print(*i)
