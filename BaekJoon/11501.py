# 하루에 주식 1개 사기 / 팔기 / 아무것도 안하기

# 먼저 든 생각, 현실 주식과 다르게 우린 미래를 알 수 있다!!! 이 이점을 이용하자
# 뒤에 큰 수가 있는걸 알면 무조건 사서 그때 파는게 나음 -> 시간 초과날 것 같은데
# 뒤에서부터 본다면, 지금 사서, 나보다 작은 애들을 만나면 그 수 만큼 * 그리고 - 걔네 숫자
# 나랑 같은 숫자일 때는 아무것도 안하지
# 나보다 큰 숫자 일때는 다시 갈아 끼기(그 큰 숫자만큼 파는게 나으니까)
# 앞에서는 이 숫자가 제일 큰 숫자인지 아리까리함... -> 복잡
import sys
input = sys.stdin.readline

for _ in range(int(input())):
  n = int(input())
  prices = [*map(int, input().split())]
  ret = 0
  big = 0
  for i in range(n-1, -1, -1): # for stock in stocks[::-1] 이렇게 하면 거꾸로 값을 받을 수 있음!!
    if big < prices[i]:
      big = prices[i]
    elif big == prices[i]: # 사실 이건 안해도, else에서 상쇄될 것!
      continue
    else:
      ret += big - prices[i]
  print(ret)
