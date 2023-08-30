#################
# 우선순위 큐를 잘 활용하자!!!!!!!!!!
import sys
input = sys.stdin.readline
import heapq

n, m = map(int, input().split())
cards = [i for i in map(int, input().split())]
heapq.heapify(cards)

for _ in range(m):
  x = heapq.heappop(cards)
  y = heapq.heappop(cards)
  heapq.heappush(cards, x+y)
  heapq.heappush(cards, x+y)

print(sum(cards))
