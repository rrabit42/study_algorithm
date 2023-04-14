# python itertools 이용
import sys
from itertools import combinations

input = sys.stdin.readline

n, m = map(int, input().split())

for i in combinations(range(1, n+ 1), m):
  print(*i)

# 재귀로 풀기
import sys

input = sys.stdin.readline
n, m = map(int, input().split())

# 재귀로 풀어보기
list = []
def re(start):
  if len(list) == m:
    print(*list)
    return
  for i in range(start, n + 1):
    if i not in list:
      list.append(i)
      re(i + 1)
      list.pop()

re(1)
