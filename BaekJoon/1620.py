# 시간 초과 뜬 내 원래 코드
total, req = map(int, input().split())

dict = {}
arr = []
for i in range(total):
  name = input()
  dict[name] = i + 1
  arr.append(name)
  
for _ in range(req):
  r = input()
  if r.isdigit():
    r = int(r) -1 
    print(arr[r])
  else:
    print(dict[r])
  
# dictonary에 key값으로 두개 다 주면 되지!
# 그리고 sys.stdin.readline 사용하기! + rstrip() => 개행문자(\n)까지 포함되므로
import sys

input = sys.stdin.readline

total, req = map(int, input().split())

dict = {}
for i in range(1, total + 1):
  name = input().rstrip()
  dict[name] = i
  dict[i] = name

for _ in range(req):
  r = input().rstrip()
  if r.isdigit():
    print(dict[int(r)])
  else:
    print(dict[r])
