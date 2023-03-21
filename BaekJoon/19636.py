import sys
import math

input = sys.stdin.readline

# 다이어트 기간: D
# 체중: W
# 일일 에너지 섭취량: l
# 일일 기초 대사량: l0
# 일일 활동 대사량: A = 0

# 체중, 일일 기초 대사량은 하루에 단 한번만 변화
# 체중 += (일일 에너지 섭취량 - 일일 에너지 소비량) = L - (l0 + A)
# 일일 에너지 소비량 = 일일 기초 대사량 + 일일 활동 대사량 = l0 + A
# |(일일 에너지 섭취량 - 일일 에너지 섭취량)| > 기초대사량 변화 역치 T 일 경우
# 일일 기초 대사량 += under((일일 에너지 섭취량 - 일일 에너지 소비량)/2)

# 체중이 0g 이하일 경우
# 일일 기초 대사량 <= 0 경우

W0, l0, T = map(int, input().split()) # 다이어트 전 체중, 일일 기초대사량(에너지 섭취량), 기초 대사량 변화 역치
D, L, A = map(int, input().split()) # 다이어트 기간, 일일 에너지 섭취량, 일일 활동 대사량

# 일일 기초 대사량의 변화를 고려하지 않았을 때 다이어트 후 예상 체중, 일일 기초 대사량
firstL = l0

expectedW = W0 + D * (L - l0 - A)
if expectedW <= 0:
  print("Danger Diet")
else:
  print(f"{expectedW} {l0}")

for d in range(D):
  # 일일 에너지 섭취량 - 일일 에너지 소비량
  c = L - l0 - A
  # 체중 변화
  W0 += c
  
  # 기초 대사량 변화
  if abs(c) > T:
    l0 += math.floor(c/2)

  if W0 <= 0 or l0 <= 0:
    break
    
if W0 <= 0 or l0 <=0:
      print("Danger Diet")
else:
  if firstL - l0 > 0:
    print(f"{W0} {l0} YOYO")
  else:
    print(f"{W0} {l0} NO")
  
# YOYO랑 NO에 싱글 따옴표 들어갔다고 틀리다고 한거 아직도 킹받네..ㅎ
