import sys
from collections import deque

input = sys.stdin.readline

cards = deque([i+1 for i in range(int(input()))])

while len(cards) != 1:
  cards.popleft()
  if len(cards) == 1:
    break
  cards.append(cards.popleft())

print(cards.pop())

# 수학적으로 풀다니.... (규칙 발견하기..?)
n,m = int(input()), 1
while m<n: # O(logn)
    m *= 2
print(2*n-m)
