import sys
input = sys.stdin.readline

N = int(input())
graph = [[i for i in map(int, input().split())] for _ in range(N)]
result = [0, 0]

def paper(x, y, n):
  check = graph[x][y]
  for i in range(x, x + n):
    for j in range(y, y+ n):
      if check != graph[i][j]:
        # 종이 나누기
        n = n // 2
        for dx in range(2):
          for dy in range(2):
            paper(x + dx * n, y + dy * n, n)
        return

  result[check] += 1


paper(0, 0, N)
print(*result, sep='\n')
