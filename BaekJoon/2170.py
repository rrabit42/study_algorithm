import sys
input = sys.stdin.readline

# 포함관계이면 첫점, 끝점만 알면 됨!
# 수업 시간이랑 비슷한듯
# 음수!!!!!

spots = []
for _ in range(int(input())):
  s, e = map(int, input().split())
  spots.append((s,e))

spots.sort(key= lambda x: x[0])

stack = []
for s, e in spots:
  if not stack or stack[-1] < s:
    stack.append(s)
    stack.append(e)
  else:
    if stack[-1] < e:
      stack.pop()
      stack.append(e)

result = 0
for i in range(0, len(stack)-1, 2):
  s, e = stack[i], stack[i+1]
  result += abs(e-s)
print(result)

#####################
# 바로바로 길이 계산
import sys

input = sys.stdin.readline

INF = -1_000_000_000

N = int(input())
lst = [tuple(map(int, input().split())) for _ in range(N)]

# stable sort
lst.sort(key=lambda x: x[0])

ans = 0
l = r = INF
for x, y in lst:
    if r < x:
        ans += r - l
        l, r = x, y
    elif r < y:
        r = y
ans += r - l

print(ans)
