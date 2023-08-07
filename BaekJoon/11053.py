# O(n^2)
import sys
input = sys.stdin.readline
n = int(input())
nums = list(map(int, input().split()))
dp = [1 for _ in range(n)]

# dp[0] = 1 이렇게 했었는데, dp[0]이 제일 작다는 보장도 없고, 모든 원소는 적어도 길이가 1인 부분집합이니까
# 1로 초기화 해줬어야 함!
for i in range(1, n):
  for j in range(i): # enumerate 써도 괜찮았을듯!
    if nums[i] > nums[j]:
      dp[i] = max(dp[j] + 1, dp[i])

# 마찬가지로 맨 마지막이 제일 길지 않으므로 Max 해줘야함!
print(max(dp))

##############################
# O(nlogn)
# A = arr 입력받은 배열
# D = dp 배열
# D[i]를 계산하기 위해 A[0] ~ A[i-1]를 꼭 다 훑어봐야 할까?
# 다 훑어본 이유 -> A[i] 보다 작은 A[j]를 가지는 j들 중 가장 큰 D[j]를 찾기 위함
# D[j] = k를 만족하는 j들 중 A[j]의 값이 가장 작은 j만 어딘가에 저장해 놓으면 나중에 D[i](i>j)를 계산할 때 그 값들만 참조하면 D[i]의 값을 쉽게 알 수 있음
# -> 즉, 같은 길이면, 그 중 가장 작은 숫자(그 자체!!!)로 저장해놓기
# D[i] = k 인 값들 중 A[i]의 값이 가장 작은 값 계속 저장
# https://namu.wiki/w/%EC%B5%9C%EC%9E%A5%20%EC%A6%9D%EA%B0%80%20%EB%B6%80%EB%B6%84%20%EC%88%98%EC%97%B4#s-3.2
# N개의 수들에 대해 X의 A[i]들을 훑어본다. X는 항상 오름차순으로 정렬되어 있으므로 이진 탐색 사용할 수 있음

#################
#스택
import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))
stack = [nums[0]]

for i in nums[1:]:
  if stack[-1] < i: # 현재 숫자가 스택 마지막 숫자보다 크면 stack 뒤에 넣어줌
    stack.append(i)
  else: # 현재 숫자가 스택 마지막 숫자보다 작으면, 스택 전체 살펴보기
    for j, v in enumerate(stack):
      if i <= v:
        stack[j] = i # 같은 길이일 때, 숫자가 작은 걸로 치환하기(더 길게 만들어주기 위해)
        break

print(len(stack))

###################3
# 이진 탐색
import sys
from bisect import bisect_left # 이진탐색 코드, 같은 수일 경우 왼쪽 index를 돌려줌, 사이 값일 경우 무조건 다음 인덱스를 찾아줌
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))
dp = []

for i in nums:
  k = bisect_left(dp, i) # 자신이 들어갈 위치
  if len(dp) <= k:
    dp.append(i)
  else:
    dp[k]= i

print(len(dp))
