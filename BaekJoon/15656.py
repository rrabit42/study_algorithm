import sys
from itertools import *
input = sys.stdin.readline

n, m = map(int, input().split())
arr = sorted(list(map(int, input().split())))

arr.sort()
result = []
def sol():
  if len(result) == m:
    print(*result)
    return

  for i in range(n):
    result.append(arr[i])
    sol()
    result.pop()

sol()

#################################
# itertools 사용
import sys
from itertools import *
input = sys.stdin.readline

n, m = map(int, input().split())
arr = sorted(list(map(int, input().split())))

arr.sort()
for i in product(arr, repeat=m):
  print(*i)
