# 접근 방법은 맞는데... 에러나는 내 코드
# 모든애들을 재귀로 print하려는건 시간이 너무 오래걸린다..!

import sys
# sys.setrecursionlimit(10**6) # 이거 넣어도 core dump 에러남
input = sys.stdin.readline
N = int(input())

# 9구역으로 나누는 문제
graph = [[' ' for _ in range(N)] for _ in range(N)]

def print_star(x, y, n):
  if n == 3:
    for i in range(3):
      for j in range(3):
        if i != 1 or j != 1: # i==1 and j ==1 이면 안되니까 그 반대는 or 임!!
          graph[i][j] = '*'
  # 9등분으로 나누기
  n = n//3
  for dx in range(3):
    for dy in range(3):
      if dx != 1 or dy != 1:
        print_star(x + n*dx, y + n*dy, n)
  
print_star(0, 0, N)
for i in range(N):
  print(*graph[i])
#################################
# 출력은 하나만 하고 나머지 애들은 간격보고 복사!

import sys
# sys.setrecursionlimit(10**6) # 이거 넣어도 core dump 에러남
input = sys.stdin.readline
N = int(input())

# 9구역으로 나누는 문제
graph = [[' ' for _ in range(N)] for _ in range(N)]

def print_star(n): # n은 length라고 보는게 이해가 편함
  if n == 3:
    # graph[1] = ['*', ' ', '*']
    # graph[0][:3] = graph[2][:3] = ['*']*3
    for i in range(3):
      for j in range(3):
        if i != 1 or j != 1:
          graph[i][j] = '*'
    return
          
  div3 = n//3
  print_star(div3)
  
  # 첫 n*n 크기의 구역을 복사해서 다른 n*n 크기 구역 찍으려는 것
  for i in range(0, n, div3): # div3 간격만큼 떨어져 있는 위치는 같은 문자 가짐
    for j in range(0, n, div3):
      if i != div3 or j != div3:
        for k in range(div3): # 복사할 구역의 행을 나타내기 위한 K(길이는 div3)
          graph[i+k][j:j+div3] = graph[k][:div3] # i, j는 구역(div3*div3)의 왼쪽 첫번째 좌표임

  
print_star(N)
for i in range(N):
  print(*graph[i], sep='')
##################################
# 재귀로 푸는 풀이는 이해는 가는데 내가 풀라고 하면 못할듯.. 참신하다 1, 2, 3째줄 분리해서 계산
# 1*1 -> 3*3 구역 얻고 -> 9 * 9 구역 얻고 -> 27 * 27 구역 얻기
# 어떻게 보면 규칙성 이용
def draw_stars(n):
  if n==1:
    return ['*']

  Stars=draw_stars(n//3)
  L=[]

  # 항상 3줄로 생각하는 것
  for star in Stars:
    L.append(star*3)
  for star in Stars:
    L.append(star+' '*(n//3)+star)
  for star in Stars:
    L.append(star*3)

  return L

N=int(input())
print('\n'.join(draw_stars(N)))
