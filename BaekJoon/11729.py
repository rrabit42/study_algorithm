import sys

input = sys.stdin.readline

n = int(input())

# 하노이 = 맨 밑 제외 나머지 원판을 2로 옮기는 횟수 + 맨 밑 원판을 3으로 옮기는 횟수(1) + 다시 맨 밑 제외 나머지 원판을 2로 옮기는 횟수
# 1번에 남은 원판을 3으로 옮기는 횟수 + 2번에 있는 원판을 3으로 옮기는 횟수
# 전체 원판 개수, 시작 장대 번호, 도착 장대 번호, (옮긴 원판 개수: 필요없는 정보; 이것보다는 중간 장대 번호가 필요함!)
def hanoi(n, start, end):
  if n == 1: # 원판이 하나 남았을 경우는 뻔함!
    print(start, end)
    return
  hanoi(n-1, start, 6-start-end) # start와 end가 아닌 장대 구하는 법: 6-start-end
  print(start, end)
  hanoi(n-1, 6-start-end, end)

# 하노이 탑 이동 횟수
print(2**n-1) # 모든 원판은 2번씩 이동, 맨 마지막 원판만 1번 이동이므로
hanoi(n, 1, 3)



################
# 하노이 탑 최소 이동 횟수 식을 모른다면?
# print문 대신 list 같은데 저장하고 출력!
