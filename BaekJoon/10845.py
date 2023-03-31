import sys
from collections import deque

input = sys.stdin.readline

q = deque()
N = int(input())

for _ in range(N):
  command = input().rstrip()
  if command == "pop":
    print(-1 if len(q) == 0 else q.popleft())
  elif command == "size":
    print(len(q))
  elif command == "empty":
    print(+(not q))
  elif command == "front":
    print(-1 if len(q) == 0 else q[0])
  elif command == "back":
    print(-1 if len(q) == 0 else q[-1])
  else:
    _, num = command.split()
    q.append(num)
