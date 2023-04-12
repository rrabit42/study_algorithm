import sys

input = sys.stdin.readline

n = int(input())

cnt = 0

i = 666
while True:
  if '666' in str(i):
    cnt += 1
  if cnt == n:
    print(i)
    break
  i += 1
  
  
  # 666의 앞, 뒤에 숫자를 붙이고 오름차순 정렬 <- 브루트포스 말고 다른 접근법
