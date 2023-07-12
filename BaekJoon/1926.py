import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
drawing = [[i for i in map(int, input().split())] for _ in range(n)]

visited = [[False for _ in range(m)] for _ in range(n)]
# visited = [[False]*m]*n 이렇게 하면 visited[a][b] 할 때 visited[a]가 모두 True가 됨
# -> [False]*m 인 목록에 n을 곱하면 동일한 list에 대한 n개의 참조가 발생하게 됨!@ wow

def bfs(a, b):
  d = deque([(a,b)])
  visited[a][b] = True
  pic = 1
  
  # 전체 좌표를 봐야함
  while d:
    x, y = d.popleft()
    
    for dx, dy in [(1,0), (0,1), (-1,0), (0, -1)]:
      nx, ny = x + dx, y + dy
      if 0 <= nx <= n-1 and 0 <= ny <= m-1 and not visited[nx][ny]:
          visited[nx][ny] = True
          if drawing[nx][ny] == 1:
            d.append((nx, ny))
            pic += 1
  return pic

largest = 0
cnt = 0
for i in range(n):
  for j in range(m):
    if drawing[i][j] == 1 and not visited[i][j]:
      pic = bfs(i, j)
      largest = max(largest, pic)
      cnt += 1
print(cnt, largest, sep='\n')

#####################################
# visited를 만들 필요 없이, 이미 들린 그림은 1을 0으로 바꿔주면 됨
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
L = [list(map(int, input().split())) for _ in range(N)]

cnt = 0
answer = 0

def bfs(i, j):
    q = [(i, j)]
    cnt = 0
    L[i][j] = 0
    while q:
        i, j = q.pop()
        cnt += 1          # 여기에다가 +1 해줘도 됨
        for dx, dy in [(1, 0) ,(0, 1) ,(-1, 0), (0, -1)]:
            nx = dx + i
            ny = dy + j
            if 0 <= nx < N and 0 <= ny < M and L[nx][ny] == 1:
                L[nx][ny] = 0
                q.append((nx, ny))
    return cnt

for i in range(N):
    for j in range(M):
        if L[i][j] == 1:
            cnt += 1
            answer = max(answer, bfs(i, j))


print(cnt)
print(answer)
