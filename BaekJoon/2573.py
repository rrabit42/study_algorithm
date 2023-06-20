import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]


def bfs(x, y):
    q = deque([(x, y)])
    visited[x][y] = 1
    seaList = []

    while q:
        x, y = q.popleft()
        sea = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                if not graph[nx][ny]:
                    sea += 1
                elif graph[nx][ny] and not visited[nx][ny]:
                    q.append((nx, ny))
                    visited[nx][ny] = 1

        if sea > 0:
            seaList.append((x, y, sea))

    # 주변 바다를 모두 탐색한 후에 한꺼번에 녹이기
    for x, y, sea in seaList:
        graph[x][y] = max(0, graph[x][y] - sea)

    return 1  # 하나의 그룹을 탐색함


# 빙산만 리스트에 선별
ice = []
for i in range(n):
    for j in range(m):
        if graph[i][j]:
            ice.append((i, j))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
year = 0

while ice:
    visited = [[0] * m for _ in range(n)]  # 연도마다 visited 갱신
    delList = []  # 바다가 된 빙산
    group = 0
    for i, j in ice:
        # 빙산 그룹 체크, 1년 경과
        if graph[i][j] and not visited[i][j]:
            group += bfs(i, j)

        # 탐색이 끝나면 바다가 된 빙산 체크
        if graph[i][j] == 0:
            delList.append((i, j))

    # 빙산 그룹이 2개 이상이면 해당 연도 출력
    if group > 1:
        print(year)
        break

    # 다 녹은 빙산은 탐색할 필요가 없으므로 ice에서 제거
    ice = sorted(list(set(ice) - set(delList)))
    year += 1

# 빙산이 다 녹았으면 0 출력
if group < 2:
    print(0)

# visited의 용도
## bfs 로직으로서 확인했던 좌표인지 확인
## 빙산 group을 확인!! -> 사실 이렇게 안하고 그냥 밑에 count += 1 이런거 해도 됨
