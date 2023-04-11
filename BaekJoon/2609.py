import sys

input = sys.stdin.readline

A, B = map(int, input().split())

L = A * B
while B:
  t = A % B

  A = B
  B = t

G = A
L = int(L / G)

print(G)
print(L)

# 베스트 풀이
def gcd(a, b):
    while b != 0:
        r = a % b
        a = b
        b = r
    return a
a, b = map(int, input().split())
print(gcd(a, b))
print(a*b // gcd(a, b))
