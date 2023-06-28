import sys

input = sys.stdin.readline

a, b, c = map(int, input().split())


# 지수 법칙, 나머지 분배 법칙
def mul(a, b, c):
  if b == 1:
    return a % c
  val = mul(a, b // 2, c)
  val = val * val % c

  if b % 2 == 0:
    return val
  return val * a % c  # b가 홀수라면 a를 한번 더 곱함


print(mul(a, b, c))
