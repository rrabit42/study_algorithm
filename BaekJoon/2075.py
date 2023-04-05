import sys
import heapq

input = sys.stdin.readline

N = int(input())

heap = []

for _ in range(N):
  for i in map(int, input().rstrip().split()):
    if len(heap) < N:
      heapq.heappush(heap, i)
    else:
      heapq.heappushpop(heap, i)

print(heapq.heappop(heap))
  
