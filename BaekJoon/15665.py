import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = sorted(set(map(int, input().split())))

result = []
def sol():
  if len(result) == m:
    print(*result)
    return

  for i in range(len(arr)):
    result.append(arr[i])
    sol()
    result.pop()

sol()

##############################
# itertools 사용
import sys
from itertools import product
input = sys.stdin.readline

n, m = map(int, input().split())
arr = sorted(set(map(int, input().split())))

for i in product(arr, repeat=m):
  print(*i)
