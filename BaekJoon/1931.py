import sys
from collections import OrderedDict
input = sys.stdin.readline

n = int(input())
dict = {}
for _ in range(n):
  start, end = map(int, input().split())
  if end in dict.keys():
    dict[end].append(start)
  else:
    dict[end] = [start]

# dictionary sort 하는 방식!!
dict = OrderedDict(sorted(dict.items(), key=lambda x:x[0], reverse=False))
num, prev_end = 0, 0

for e, s in dict.items():
  # 회의가 끝나는 시간이 같다면, 회의가 빨리 시작하는 회의를 넣기
  s.sort()
  for start in s:
    # 시작시간=종료시간이 같은 회의는 무조건 넣기 가능(깍두기)
    # 깍뚜기가 여러개 일 수 있음!! -> Wow 모두 더해줘야 함
    if start >= prev_end:
      if start == e:
        num += 1
      else:
        num += 1
      prev_end = e

  # 기존 틀린 깍두기 코드
  # if len(s) != 1 and s[-1] == e:
  #   num += 1

print(num)


# 베스트 풀이
# 회의실 끝 시간부터 살펴보기
import sys
In = sys.stdin.readline

def main():
    n = int(input())
    schedules = [(*map(int, In().split(' ')),) for i in range(n)]
    schedules.sort()
    result, lastTime = 0, float('inf')
    for a, b in reversed(schedules):
        if b <= lastTime:
            lastTime = a
            result += 1
    print(result)

main()
