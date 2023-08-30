#################
# 최종 코드

import sys
input = sys.stdin.readline
import heapq

n = int(input())

classes = []
for _ in range(n):
  s, e  = map(int, input().split())
  classes.append((s,e))

classes.sort(key=lambda x: x[0])

# 끝나는 시간 저장해둔 배열
# 제일 작은 끝나는 시간보다 수업 시작하는 시간이 더 적으면 교실 더 추가해야함!! ***
room = [0]
for s, e in classes:
  if room[0] <= s:
    heapq.heappop(room)
  heapq.heappush(room, e)
    
print(len(room))

###############################
# 시간 초과 내 코드(끝나는 시간 기준) -> 리스트가 진짜 느린가보다...
import sys
input = sys.stdin.readline

n = int(input())

classes = []
for _ in range(n):
  classes.append(tuple(map(int, input().rstrip().split())))

classes.sort() # !! 이럴거면 그냥 우선순위 큐를 쓰는 것도 방법일듯
open = []
for s, t in reversed(classes): # 강의 끝나는 시간 기준
  open.sort() 
  find = False
  for i, v in enumerate(open):
      if t <= v:
        open[i] = s
        find = True
        break
  # 사용할 수 있는 강의실이 없을 경우
  if not find:
    open.append(s)

print(len(open))

#################################
# O(N*2) 부분을 바꿔봄
import sys
input = sys.stdin.readline

n = int(input())

classes = []
for _ in range(n):
  classes.append(tuple(map(int, input().rstrip().split())))

classes.sort(reverse=True) # !! 이럴거면 그냥 우선순위 큐를 쓰는 것도 방법일듯
open = []
for s, t in classes: # 강의 끝나는 시간 기준
  if not open: # 처음에 마지막 강의 시작하는 시간 넣기
    open.append(s)
    continue
  open.sort()
  if t <= open[-1]:
    open[-1] = s
    continue
  # 사용할 수 있는 강의실이 없을 경우
  open.append(s)

print(len(open))

############################
# 성공 코드(heapq는 min heap이므로 시작하는 시간 기준으로 쓰는게 맞지만, 시간 초과 비교를 위해 위와 같은 끝나는 시간 기준으로 함)

import sys
import heapq
input = sys.stdin.readline

n = int(input())

classes = []
for _ in range(n):
  classes.append(tuple(map(int, input().rstrip().split())))

classes.sort(key=lambda x: x[1], reverse=True) # 여기 정렬 주의!!
open = []

for i, v in enumerate(classes):
  if not open:
    heapq.heappush(open, -classes[0][0]) # 첫번째 강의가 시작하는 시간
    continue
  if open[0] <= -classes[i][1]:
    heapq.heappop(open)
  heapq.heappush(open, -classes[i][0])

print(len(open))

#############################
# 성공 코드
import sys
import heapq
input = sys.stdin.readline

n = int(input())

classes = []
for _ in range(n):
  classes.append(tuple(map(int, input().rstrip().split())))

classes.sort()
open = []

# 시작하는 시간 기준
for i in range(n):
  if not open:
    heapq.heappush(open, classes[0][1])
    continue
  if open[0] <= classes[i][0]:
    heapq.heappop(open)
  heapq.heappush(open, classes[i][1])

print(len(open))
