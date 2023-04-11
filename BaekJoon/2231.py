import sys

input = sys.stdin.readline

n = input().rstrip()

def sum(n):
  for i in range(int(n) + 1):
    s = i
    for x in str(i):
      s += int(x)
    if s == int(n):
      return i

  return 0

print(sum(n))


# 범위 줄이기 + map 활용
N = int(input())
ans = 0
for i in range(max(0, N - len(str(N)) * 9),N):
    if sum(map(int,str(i))) + i == N:
        ans = i
        break
print(ans)


# 나도 아래와 같이 줄이고 싶었는데 음수일 경우 그냥 0 으로 할걸 그랬나봐.. 완벽하게 줄이고 싶었는데..
import sys

input = sys.stdin.readline

n = input().rstrip()

def sum(n):
  # a + b + c 해서 n 이 나오게 하는 가장 작은 값, 없으면 0
  # 범위 줄이기
  for i in range(int(n) - (len(n) - 1) * 9, int(n) + 1):
    s = i
    for x in str(i):
      s += int(x)
    if s == int(n):
      return i

  return 0

print(sum(n))
