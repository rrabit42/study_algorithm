import sys
from collections import deque
input = sys.stdin.readline

queue = deque()

n = int(input())
for _ in range(n):
  num = int(input())
  if num == 0 and len(queue) != 0:
    queue.pop()
  else:
    queue.append(num)

print(sum(queue))
