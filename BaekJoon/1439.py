import sys
input = sys.stdin.readline

n = input().rstrip()

def flip(n):
  zeros = n.count('0')
  ones = n.count('1')
  if zeros == len(n):
    return 0
  elif ones == len(n):
    return 0

  z_cnt = 0
  o_cnt = 0
  # 전체 1로 만드는게 필요한 최소 횟수
  for i in n.split('1'):
    if i != '':
      o_cnt += 1
  # 0
  for j in n.split('0'):
    if j != '':
      z_cnt += 1
  return min(z_cnt, o_cnt)

print(flip(n))


###############################
# 와 이건 뭐냐...
# 0 -> 1로 변화, 1 -> 0로 변화하는 횟수 중에 큰걸 고르는 이유는?
# 문자 길이에 상관없이 문자가 바뀌는지만 보면 됨! ex) 0001100 -> 010로 봐도 무방함
# 큰게 끊어진 횟수이기 때문! 끊어진 횟수만큼 flip 하면 됨
c=input().count
print(max(c("01"),c("10")))

###############################
# 내가 한 방법의 상위 호환 버전
s = input()
print(min(len(s.replace('0', ' ').split()), len(s.replace('1', ' ').split())))

##############################
# 규칙에 따라 코드 짜기
# 문자 길이에 상관없이 문자가 바뀌는지만 보면 됨! ex) 0001100 -> 010로 봐도 무방함
S = input()
count = 0
for i in range(len(S)-1):
    if S[i] != S[i+1]:
        count += 1
print((count + 1) // 2)
