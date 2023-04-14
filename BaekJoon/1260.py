import sys
from collections import deque

input = sys.stdin.readline

# N: 정점 개수, M: 간선 개수, 시작 정점: V
N, M, V = map(int, input().split())
line = [[] for _ in range(N + 1)]

for _ in range(M):
  a, b = map(int, input().split())
  line[a].append(b)
  line[b].append(a)

  # 오름차순으로 들어가 있어야 함
  line[a].sort()
  line[b].sort()

def dfs(start):
  visited = []
  stack = [start]

  while stack:
    n = stack.pop()
    if n not in visited:
      visited.append(n)
      for i in range(len(line[n]) - 1, -1, -1):
        if line[n][i] not in visited:
          stack.append(line[n][i])
  return visited

print(*dfs(V))

def bfs(start):
  visited = []
  queue = deque()
  queue.append(start)

  while queue:
    n = queue.popleft()
    if n not in visited:
      visited.append(n)
      for adj in line[n]:
        if adj not in visited:
          queue.append(adj)
  return visited

print(*bfs(V))
