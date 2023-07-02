import sys

input = sys.stdin.readline

n = int(input())
arr = [list(map(int, input().rstrip())) for _ in range(n)]

# 분할 정복
# Z 그리는 순서대로 1 -> 2 -> 3 -> 4
def z(x, y, n):
  all = arr[x][y]
  for i in range(x, x+ n):
    for j in range(y, y+n):
      if all != arr[i][j]:
        all = -1
        break
    if all == -1:
      break
      
  if all == -1:
    print("(", end='')
    n = n//2
    z(x, y, n) # 1사분면
    z(x, y + n, n) # 2사분면
    z(x + n, y, n) # 3사분면
    z(x + n , y+ n, n) # 4사분면
    print(")", end='')
  elif all == 1:
    print(1, end='')
  else:
    print(0, end='')

z(0, 0, n)


#############################
# 재귀로 풀기

import sys
n = int(input())
a = []
for _ in range(n):
    a.append(sys.stdin.readline().strip())

def zi(x,y,k):
    if k==1:
      return a[x][y]
    nk = k//2
    d1,d2,d3,d4 = zi(x,y,nk),zi(x,y+nk,nk),zi(x+nk,y,nk),zi(x+nk,y+nk,nk)
    if d1 =='0' or d1 =='1': # d1이 '01', '10'이 아니어야 함!!
      if d1 == d2 and d2 == d3 and d3 == d4: # 모든 분면의 숫자가 같으면
            return d1
    return '('+d1+d2+d3+d4+')'

print(zi(0,0,n))
