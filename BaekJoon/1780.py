import sys
input = sys.stdin.readline

N = int(input())
graph = [[i for i in map(int, input().split())] for _ in range(N)]

# 분할 정복

minusOne, zero, one = 0,0,0

def slice(x, y, n):
  global minusOne, zero, one
  # 전체가 같은 종이로 되어 있는지 확인
  check = graph[x][y]
  for i in range(x, x+n):
    for j in range(y, y+n):
      if graph[i][j] != check:
        check = 2
    else: # python else의 이런 문법도 있었다!!!!! 이 else는 nested loop 의 inner loop 안에 있는 if와 연결됨
      continue
      
  if check == 2:
    # 9등분으로 나누기
    n = n // 3
    for dx in range(3):
      for dy in range(3):
        nx = x + dx * n
        ny = y + dy * n
        slice(nx,ny, n)
  elif check == 1:
    one += 1
  elif check == -1:
    minusOne += 1
  elif check == 0:
    zero += 1

slice(0, 0, N)
print(f'{minusOne}\n{zero}\n{one}\n')

#########################
# 좀 더 결과를 효율적으로 다루는 법! -> list와 index 활용
import sys
input = sys.stdin.readline

N = int(input())
graph = [[i for i in map(int, input().split())] for _ in range(N)]

# 분할 정복
result = [0,0,0]

def slice(x, y, n):
  # 전체가 같은 종이로 되어 있는지 확인
  check = graph[x][y]
  for i in range(x, x+n):
    for j in range(y, y+n):
      if graph[i][j] != check:
        check = 2
    else:
      continue
      
  if check == 2:
    # 9등분으로 나누기
    n = n // 3
    for dx in range(3):
      for dy in range(3):
        nx = x + dx * n
        ny = y + dy * n
        slice(nx,ny, n)
  else:
    result[check + 1] += 1

slice(0, 0, N)
print(*result, sep='\n')
