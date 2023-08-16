import sys
input = sys.stdin.readline

n = int(input())
rope = []
w = []
for _ in range(n):
  rope.append(int(input()))
  w.append(0)

rope.sort()
# 최소 중량 * 로프 수가 최대 무게임!
for i in range(n):
  w[i] = rope[i] * (n-i) # 여기를 이렇게 바꿔줌!

print(max(w))

############################
# 호오..
from sys import *
input=stdin.readline
x=sorted([int(input()) for i in range(int(input()))])
print(max([x[-i]*i for i in range(1,len(x)+1)])) # 음수 인덱스 이용해서 i를 개수 그자체로 만들어버리기! 호,,,

###########################
# 시간 초과
import sys
input = sys.stdin.readline

n = int(input())
rope = []
w = []
for _ in range(n):
  rope.append(int(input()))
  w.append(0)

rope.sort()
# 최소 중량 * 로프 수가 최대 무게임!
for i in range(n):
  w[i] = rope[i] * len(rope[i:])

print(max(w))
