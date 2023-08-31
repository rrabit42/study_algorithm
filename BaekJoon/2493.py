import sys
input = sys.stdin.readline

n = int(input())
b = list(map(int, input().split()))

result = [0]
stack = [0] # index를 stack으로 쌓기
for i in range(1, n):
  while stack and b[stack[-1]] <= b[i]:
    stack.pop()
  
  if not stack:
    result.append(0)
  else:
    result.append(stack[-1]+1)
  
  stack.append(i)

print(*result)

##############################
# 뒤에서부터 계산
# 내가 내 오른쪽에 있는 애보다 높으면, 내가 그 애의 result가 되는 것!
# 그렇게 result를 한꺼번에 계산해준다

n = int(input())
A = list(map(int, input().split()))

stack = []
answer = [0] * n

for i in range(n-1, -1, -1):
    while stack and A[stack[-1]] < A[i]:
        idx = stack.pop()
        answer[idx] = i + 1
    stack.append(i)

print(' '.join(map(str, answer)))
