import sys
input = sys.stdin.readline

r, c = map(int, input().split())
yard = [list(input().rstrip()) for _ in range(r)]
visited = [[False for _ in range(c)] for _ in range(r)]

# . 빈필드 / # 울타리 / o 양 / v 늑대
def bfs(a, b):
  stack = [(a,b)]
  sheep, wolf = 0, 0
  
  while stack:
    x, y = stack.pop()
    visited[x][y] = True
    # 양, 늑대 개수 세기
    if yard[x][y] == 'o':
      sheep += 1
    elif yard[x][y] == 'v':
      wolf += 1
    
    for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
      nx, ny = x + dx, y + dy
      if 0<=nx<r and 0<=ny<c and not visited[nx][ny] and yard[x][y] != '#':
        stack.append((nx, ny))
        visited[nx][ny] = True # 와 이거의 유무를 느낌...
  return sheep, wolf

survive_sheep, survive_wolf = 0, 0
for i in range(r):
  for j in range(c):
    if not visited[i][j] and yard[i][j] != '#':
      s, w = bfs(i, j)
      if s > w:
        survive_sheep += s
      else:
        survive_wolf += w

print(survive_sheep,survive_wolf)
