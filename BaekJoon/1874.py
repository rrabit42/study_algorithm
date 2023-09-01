import sys
input = sys.stdin.readline

n = int(input())

result = []
stack = []

i = 1
for _ in range(n):
  target = int(input())

  # 스택이 비어 있거나, 더 채울 여지가 있으면 채우셈!
  if not stack or stack[-1] < target:
    for num in range(i, target + 1):
      stack.append(num)
      result.append('+')
    i = stack[-1] + 1

  # 이제 수열을 만들 수 있는지 없는지 판단
  if stack[-1] == target:
    stack.pop()
    result.append('-')
  else:
    break

if stack:
  print('NO')
else:
  print(*result, sep='\n')

##################################
# 정석 코드인듯. 풀이는 같음!

import sys

def solution():
    n, *nums = map(int, sys.stdin.buffer.read().splitlines())
    s = []
    answer = []
    cur = 1
    for value in nums:
        while cur <= value:
            answer.append('+')
            s.append(cur)
            cur += 1
        if s.pop() != value:
            return "NO"
        answer.append('-')
    return '\n'.join(answer)


print(solution())
