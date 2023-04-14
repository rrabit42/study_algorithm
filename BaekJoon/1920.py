# binary search(정석)
import sys

input = sys.stdin.readline

n = int(input())
nums = sorted(list(map(int, input().split())))

m = int(input())
check = list(map(int, input().split()))  # set은 순서를 지키지 않음

for target in check:
  first, last = 0, n-1
  isExist = False
  
  while first <= last:
    mid = (first + last) // 2
    if target == nums[mid]:
      isExist = True
      break
    elif target < nums[mid]:
      last = mid - 1 # mid를 다시 범위에 넣는건 소용이 없으므로 +- 1 해줘야함
    else:
      first = mid + 1
  print(1) if isExist else print(0)

# set으로 푸는 법
import sys

input = sys.stdin.readline

n = int(input())
nums = set(map(int, input().split()))

m = int(input())
check = list(map(int, input().split()))  # set은 순서를 지키지 않음

print(check)
for c in check:
    print(1) if c in nums else print(0)

# 베스트
input()
a = set(input().split())
input()
answer = '\n'.join('1' if x in a else '0' for x in input().split())
print(answer, end='')
