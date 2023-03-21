import sys

input = sys.stdin.readline

carNum = int(input())
before = {input().rstrip(): x for x in range(carNum)}
after = [input().rstrip() for x in range(carNum)]

result = 0

# 반례: 추월을 했음에도 rank는 같거나 작을 수 있음
# for car, rank in after.items():
#     if rank < before[car]:
#         result += 1

# after에서 뒤에 나오는 차량보다 내가 인덱스가 더 크면 추월한 것!
for i in range(carNum-1):
  for j in range(i+1, carNum):
    # 제일 먼저 나온 차의 원래 순번 > 그 뒤에 나온 차의 원래 순번
    # 순번이 크다는건 뒤에 있었다는 뜻
    if before[after[i]] > before[after[j]]:
      result += 1
      break

print(result)
