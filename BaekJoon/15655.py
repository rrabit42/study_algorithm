import sys
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
    sol(i+1)
    result.pop()

sol(0)

###############################
# itertools 사용해서 풀기

import sys
from itertools import combinations
input = sys.stdin.readline

n, m = map(int, input().split())
arr = sorted(list(map(int, input().split())))

arr.sort()

for i in combinations(arr, m):
  print(*i)

#################################
# python 테크닉
from itertools import *
n, m = map(int, input().split())
for i in combinations(sorted(map(int, input().split())), m):
  print(*i)
