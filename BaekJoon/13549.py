import sys
from collections import deque

input = sys.stdin.readline
MAX = 100000 + 1

n, k = map(int, input().split())
visited = [-1] * MAX  # [위치][시간] 으로 하려고 했으나 메모리 초과로 [위치]=시간으로 바꿈(물론 dist 배열을 따로 둬도 됨)

def bfs():
    q = deque()
    q.append(n)
    visited[n] = 0

    while q:
        loc = q.popleft()

        # 동생 위치를 찾음
        if loc == k:
            return visited[loc]

        # 순간이동
        if loc * 2 < MAX and visited[loc*2] == -1:
            visited[loc*2] = visited[loc]
            q.appendleft(loc*2) # 2*s가 다른 연산보다 더 높은 우선순위를 가지기 위함(순간이동이 최단시간 도출에 핵심이라 먼저 해야 값이 저장됨)

        # 걷기
        for dx in [-1, 1]:
            nx = loc + dx
            if 0 <= nx < MAX and visited[nx] == -1:
                visited[nx] = visited[loc] + 1
                q.append(nx)


print(bfs())
