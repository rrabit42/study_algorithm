import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]

# 섬 찾기
def bfs(i, j):
  queue = deque([(i,j)])
  visited[i][j] = True
  graph[i][j] = island

  while queue:
    x, y = queue.popleft()
    # lands.append((x,y))
    for dx, dy in [(1, 0), (-1,0), (0,-1), (0,1)]:
      nx = x + dx
      ny = y + dy
      if 0 <= nx < n and 0 <= ny < n and graph[nx][ny] and not visited[nx][ny]:
        graph[nx][ny] = island
        visited[nx][ny] = True
        queue.append((nx, ny))

  # return lands

# 최소 거리 찾기(이루는 좌표 차 중에 가장 작은 숫자)
# 좌표로 찾을 수 없음. 또 bfs 돌면서 거리 차를 구해야함
bridge = n*4
def findBridge(k): # 바다 건너면서 가장 짧은 다리 구함
  global bridge
  dist = [[-1] * n for _ in range(n)] # 거리 저장 배열
  q = deque()

  for i in range(n):
    for j in range(n):
      if graph[i][j] == k:
        q.append((i,j))
        dist[i][j] = 0

  while q:
    x, y = q.popleft()
    for dx, dy in [(1, 0), (-1,0), (0,-1), (0,1)]:
      nx = x + dx
      ny = y + dy
      # 갈 수 없는 곳이면 continue
      if nx < 0 or nx >= n or ny < 0 or ny >= n:
        continue
      # 다른 땅을 만나면 기존 답과 비교하여 짧은 거리 선택
      if graph[nx][ny] > 0 and graph[nx][ny] != k:
        bridge = min(bridge, dist[x][y])
        return
      # 바다를 만나면 dist를 1씩 늘린다
      if graph[nx][ny] == 0 and dist[nx][ny] == -1:
        dist[nx][ny] = dist[x][y] + 1
        q.append((nx, ny))

# main
island = 1 # 섬끼리 숫자로 구분
# lands = [] # 섬
visited = [[False for _ in range(n)] for _ in range(n)]

for i in range(n):
  for j in range(n):
    if not visited[i][j] and graph[i][j]:
      # lands.append(bfs(i,j))
      bfs(i,j)
      island += 1

for i in range(1, island):
  findBridge(i)

print(bridge)
  
# 아니면 섬이 아닌곳을 중점으로 생각해서 무언가를 할 수는 없을까?(서로 다른 섬이라는걸 구분할 수 있을까?)

