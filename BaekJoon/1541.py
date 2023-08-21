import sys
input = sys.stdin.readline

def plus(line):
  t = 0
  for num in line.split('+'):
    t += int(num)
  return t

result = 0
# 최소: - 나오는 순간부터 다 -되게 괄호 쳐주면 됨!
for i, line in enumerate(input().rstrip().split('-')):
  if i == 0:
    result += plus(line)
  else:
    result -= plus(line)

print(result)

######################################
# 와우 진짜 발상의 전환이다...
# l[0]만 더해주는 값이고 나머지는 빼주는 값임. 그래서 반대로 그렇게 계산하고, 마지막에 - 붙이는것!

l=[sum([int(i) for i in s.split("+")]) for s in input().split("-")]
print(-1*(sum(l)-2*l[0]))
