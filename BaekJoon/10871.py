import sys

input = sys.stdin.readline

n, x = map(int, input().split())
arr = list(map(int, input().split()))

for a in arr:
  if a < x:
    print(a, end=' ')


##############
# 다른 풀이
answer = ' '.join([i for i in input().split() if int(i) < x])
print(answer)
