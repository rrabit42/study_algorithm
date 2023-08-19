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

########################################
# 깍두기가 여러개일 경우, min 작업 때문에 하나의 경우의 수로 뭉개짐
# 틀린 풀이!
import sys
from collections import OrderedDict
input = sys.stdin.readline

n = int(input())
m = {}

for _ in range(n):
  s, e = map(int, input().split())
  if s in m:
    m[s] = min(m[s], e) # 같은 시간에 시작하면 빨리 끝나는게 낫지
  else:
    m[s] = e

# 빨리 끝나는 순으로 정렬
m = OrderedDict(sorted(m.items(), key=lambda x: x[1], reverse=False))
num, prev_end = 0, 0

# 그 시간에 회의 개수 최대
for s, e in m.items():
  if s >= prev_end:
    num +=1
    prev_end = e

print(num)

#########################################
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
#####################################
# 정렬만 잘해도 풀 수 있는 문제!
# 순서대로 빈틈없이 회의실을 사용하면 된다. 앞에서든, 뒤에서든!

N = int(input())
time = []

for _ in range(N):
  start, end = map(int, input().split())
  time.append([start, end])

time = sorted(time, key=lambda a: a[0]) # 시작 시간을 기준으로 오름차순
time = sorted(time, key=lambda a: a[1]) # 끝나는 시간을 기준으로 다시 오름차순

last = 0 # 회의의 마지막 시간을 저장할 변수
conut = 0 # 회의 개수를 저장할 변수

for i, j in time:
  if i >= last: # 시작시간이 회의의 마지막 시간보다 크거나 같을경우
    conut += 1
    last = j

print(conut)
