# 파이썬 아니면 못풀었을 수도... visit 까지는 생각했고 아마 set 이용해서 풀었을 것 같다
import sys
from itertools import permutations
input = sys.stdin.readline

n, m = map(int, input().split())
arr = sorted(list(map(int, input().split())))
arr.sort()

result = []
visit = [False]*n
def sol():
  if len(result) == m:
    print(*result)
    return
  prev = 0
  for i in range(n):
    if not visit[i] and prev != arr[i]: # 숫자당 1번만 들어가도록 + 중복 수열 방지
      visit[i] = True
      result.append(arr[i])
      sol()
      prev = result.pop()
      visit[i] = False

sol()

##################################
# itertools

import sys
from itertools import permutations
input = sys.stdin.readline

n, m = map(int, input().split())
arr = sorted(list(map(int, input().split())))

arr.sort()

for i in sorted(set(permutations(arr, m))):
  print(*i)
