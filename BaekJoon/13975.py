import sys
import heapq

input = sys.stdin.readline

t = int(input())
for _ in range(t):
  k = int(input())
  files = list(map(int, input().split()))

  # 가장 작은것끼리 합쳐지도록
  heapq.heapify(files)
  if k == 1:
    print(files[0])
    continue

  cost = 0
  while len(files) > 1:
    a = heapq.heappop(files)
    b = heapq.heappop(files)
    tmp = a+b
    cost += tmp
    heapq.heappush(files, tmp)
  print(cost)
  
  
# 아래는 내가 했던 잘못된 풀이... 깜빡 속았다..ㅎ...
# 가장 작은 것과 가장 큰 게 합쳐지는게 나을듯...?
# for _ in range(t):
#   k = int(input())
#   files = sorted(list(map(int, input().split())))

#   cost = 0
#   while len(files) > 1:
#     temp = []
#     k = len(files)
#     for i in range(0, k//2):
#       t = files[i] + files[k - 1 - i]
#       print(f'i: {i} t: {t}')
#       temp.append(t)
#     if k % 2 != 0:
#       temp.append(files[k//2])
  
#     cost += sum(temp)
#     files = sorted(temp)
#     print(files)

#   print(cost)

# 제일 빠른 풀이
