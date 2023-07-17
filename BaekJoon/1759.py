import sys
input = sys.stdin.readline

l, c = map(int, input().split())
arr = sorted(input().rstrip().split())

pw = [] # 최소 1개 모음, 최소 2개 자음, 중복 X
vowel = ['a', 'e', 'i', 'o', 'u']

def sol(start, vo, co):
  if len(pw) == l and vo >= 1 and co >= 2: # 자음을 따로 세지 않고 그냥 전체 길이에서 모음 뺴면 나머지가 자음임!!
    print(*pw, sep='')
    return

  for i in range(start, c):
    pw.append(arr[i])
    if arr[i] in vowel:
      sol(i+1, vo+1, co)
    else:
      sol(i+1, vo, co+1)
    pw.pop()

sol(0, 0, 0)
###########################
# itertools 이용
import sys
from itertools import combinations
input = sys.stdin.readline

l, c = map(int, input().split())
arr = sorted(input().rstrip().split())

cases = combinations(arr, l)

for pw in cases:
  vowel = 0
  for i in pw:
    if i in "aeiou":
      vowel += 1

  if vowel >= 1 and l - vowel >= 2:
    print(''.join(pw))

# set 이용해서 자음 개수 세기
from itertools import combinations

l,c=map(int,input().split())
strs=sorted(list(input().split()))

vowel=set('aeiou')
for i in combinations(strs,l):
	check=set(i)-vowel
	c=len(check)
	if c>=2 and l-c>=1:
		print("".join(i))
