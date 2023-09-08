import sys

input = sys.stdin.readline

for _ in range(int(input())):
  clothes = {}
  # 옷 분류
  for _ in range(int(input())):
    cloth, type = input().rstrip().split()
    if type in clothes:
      clothes[type] += 1
    else:
      clothes[type] = 1
  # 분류 대로 코디하기
  # +1 해서 숫자를 모두 곱하고 -1(알몸)
  result = 1
  for _, v in clothes.items():
    result *= (v + 1)  # 이 분류를 코디에 포함하지 않는 경우의 수
  print(result - 1)
