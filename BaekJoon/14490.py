import sys

input = sys.stdin.readline

n, m = list(map(int, input().split(":")))

# 최대 공약수 구하기
def GCD(a, b):
  while b:
    t = a % b
    a = b
    b = t

  return a

g = GCD(n,m)
print(f'{n//g}:{m//g}')


# 베스트 풀이
n, m = map(int, input().split(":"))

def gcd(a,b):
    while b != 0:
        a,b = b, a%b
    return a

g = gcd(n,m)
print(f"{n//g}:{m//g}")
