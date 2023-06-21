import sys
from collections import deque
input = sys.stdin.readline

# 상하좌우, 체스 나이트 이동
monkey = [[1,0],[0,1],[-1,0],[0,-1]]
horse = [[-2,-1], [-2,1],[-1,-2],[-1,2],[2,-1],[2,1],[1,-2],[1,2]]

K = int(input()) # 체스 나이트처럼 움직일 수 있는 횟수
W, H = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(H)]

## 특정 이동 방식에 횟수가 정해져 있을 때 3차원 배열 활용!
## 즉, 방문 처리 배열을 3차원으로 나타냄: visited[열][행][이동수]
# 난 재귀 생각하고 있었음,,ㅋ,,,

# (0,0) -> (W, H)

def bfs():
  visited = [[[0]*(K+1) for _ in range(W)] for _ in range(H)]
  # ** 순서가 층, 열, 행; 즉 W가 열 = y, H가 행 = x
  queue = deque()
  queue.append([0,0,0])
  visited[0][0][0] = 1

  while queue:
    x, y, z = queue.popleft()

    # 목표 지점에 도달하면 return (이 데이터가 pop되기 전에 이미 모든 경우의 수는 돌았음)
    if x == H - 1 and y == W - 1:
      return visited[x][y][z] - 1 # (0,0,0) 에서 1이었으므로 빼준다
  
    # 상하 좌우로 이동
    for i, j in monkey:
      dx, dy = x + i, y + j
      if 0 <= dx < H and 0 <= dy < W and not visited[dx][dy][z] and not graph[dx][dy]:
        visited[dx][dy][z] = visited[x][y][z] + 1
        queue.append([dx, dy, z])
  
    # 말 이동 수보다 작을 경우에만 이동
    if z < K:
      for hi, hj in horse:
        hx, hy = x + hi, y + hj
        if 0 <= hx < H and 0 <= hy < W and not graph[hx][hy]:
          # 움직이면 z + 1번째로 이동하는거니까 z+1층에 대입
          if not visited[hx][hy][z+1]:
            visited[hx][hy][z+1] = visited[x][y][z] + 1
            queue.append([hx, hy, z+1])
    
  return -1

print(bfs())
