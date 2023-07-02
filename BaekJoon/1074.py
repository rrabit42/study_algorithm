# 분할 정복 풀이
import sys

input = sys.stdin.readline

n, r, c = map(int, input().split())

# 2^n-1로 4등분한 후 재귀적으로 방문
# 행열 헷갈리지 말것!
def visit(n, x, y, start):
  if n == 0:
    return start
  # 4분면 결정(내멋대로 1 -> 2 -> 3 -> 4)
  num, nx , ny = 0, x, y
  next = 2**(n-1)
  if x < next:
    if y < next:
      num = 0 # 1사분면
    else: # 2사분면
      num = 1
      ny -= next
  else:
    nx -= next
    if y < next: # 3사분면
      num = 2
    else: # 4사분면
      num = 3
      ny -= next
  # 4분면의 개수만큼 더해줌
  start += next ** 2 * num
  return visit(n-1, nx, ny, start)

print(visit(n, r, c, 0))

##########################
# 좀 더 깔끔한 풀이
N, r, c = map(int, input().split())

ans = 0

while N != 0:

	N -= 1

	# 1사분면
	if r < 2 ** N and c < 2 ** N:
		ans += ( 2 ** N ) * ( 2 ** N ) * 0

	# 2사분면
	elif r < 2 ** N and c >= 2 ** N: 
		ans += ( 2 ** N ) * ( 2 ** N ) * 1
		c -= ( 2 ** N )
        
	# 3사분면    
	elif r >= 2 ** N and c < 2 ** N: 
		ans += ( 2 ** N ) * ( 2 ** N ) * 2
		r -= ( 2 ** N )
        
	# 4사분면    
	else:
		ans += ( 2 ** N ) * ( 2 ** N ) * 3
		r -= ( 2 ** N )
		c -= ( 2 ** N )
    
print(ans)

##########################
# 4분면 결정을 이렇게 할 수도 있군
n, r, c = map(int, input().split())
r+=1
c+=1
n=2**n
x=0
while n>1:
    n*=0.5
    q=(1 if r<=n else 3)+(0 if c<=n else 1)
    x+=n**2*(q-1)
    r-=n if n<r else 0
    c-=n if n<c else 0
print(int(x))

###########################
# 와우 이게 진짜 재귀 풀이
# r, c가 2배가 됨에 따라 값 차이가 4의 배수(4의 배수로 확장)
n, r, c = map(int,input().split())
def z(n, r, c):
    if n == 0 :
        return 0
    return 2*(r%2)+c%2 + 4*z(n-1, r//2, c//2) 
print(z(n, r, c))

# 2*(r%2)+(c%2) : 4의 배수인 값으로부터 네모칸에서 이동한 값(r는 세로인 행이므로, 나머지가 있으면 2씩 확장/ c는 가로인 열이므로 나머지가 있으면 1씩만 값이 늘어남)
# 4*sol( N-1, int(r/2), int(c/2) ) : 4의 배수 하기 이전에 값
