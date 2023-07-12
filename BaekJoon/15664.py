import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = sorted(list(map(int, input().split())))
arr.sort()

result = []
visited = [False]*n
def sol(start):
  if len(result) == m:
    print(*result)
    return

  prev = 0
  for i in range(start, n):
    if prev == arr[i] or visited[i]:
      continue
    visited[i] = True
    result.append(arr[i])
    sol(i + 1)
    prev = result.pop()
    visited[i] = False

sol(0)

###############################
# itertools 이용해서 풀기

import sys
from itertools import combinations
input = sys.stdin.readline

n, m = map(int, input().split())
arr = sorted(list(map(int, input().split())))
arr.sort()

for i in sorted(set(combinations(arr, m))):
  print(*i)
