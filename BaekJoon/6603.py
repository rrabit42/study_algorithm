import sys
from itertools import combinations
input = sys.stdin.readline


while True:
  t = list(map(int, input().split()))
  if t[0] == 0:
    break
  
  k, arr = t[0], t[1:]

  for i in combinations(arr, 6):
    print(*i)
  print()
##############################
import sys
from itertools import combinations
input = sys.stdin.readline

def sol(result, arr, start):
  if len(result) == 6:
    print(*result)
    return

  for i in range(start, len(arr)):
    result.append(arr[i])
    sol(result, arr, i + 1)
    result.pop()

while True:
  t = list(map(int, input().split()))
  if t[0] == 0:
    break
  
  k, arr = t[0], t[1:]

  sol([], arr, 0)
  print()
