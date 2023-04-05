import sys
import heapq

input = sys.stdin.readline

N = int(input())

# heapq는 최소힙을 만드므로, 음수로 만들어서 최대힙처럼 사용
heap = []
for _ in range(N):
  n = int(input())

  if n == 0:
    if heap:
      top = -heapq.heappop(heap)
      print(top)
    else:
      print(0)
  else:
    heapq.heappush(heap, -n)
