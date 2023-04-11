import sys

input = sys.stdin.readline

N = int(input())
k = list(map(int, input().split()))
p = max(k)

isPrime = [1] * (p + 1)
for i in range(2, int(p**0.5) + 1):
    if isPrime[i] == 1:
        for j in range(i * i, p + 1, i):
            if isPrime[j] == 1:
                isPrime[j] = i

for n in k:
  while isPrime[n] != 1:
      print(isPrime[n], end=" ")
      n = n // isPrime[n]
  print(n)
    # stack = []
    # while n != 1:
    #   stack.append(isPrime[n])
    #   n = n // isPrime[n]
    # print(*stack)

# 두 풀이 참조했는데 어디서 시간초과 뜨는지 이해를 못하겠음
# 1
#정답코드,배열사용
def p(n,d): #에라토스테네스의 체
    s = [1] * n
    m = int(n**0.5)
    for i in range(2,m+1):
        if s[i] == 1:#소수인 경우
            for j in range(i+i,n,i):#소수의 배수에 대해
                s[j] = 0
                if d[j] == j:
                    d[j] = i #가장 작은 소인수 입럭
a = int(input())
b = list(map(int,input().split()))
g = [i for i in range(5000001)]
c = p(5000001,g)
for i in range(a):
    e = []
    f = b[i]
    while f > 1:
        e.append(g[f])
        f = f // g[f]
    for i in e:
        print(i,end = " ")
    print()

# 2
# 16563번 : 어려운 소인수분해 – Gold 4
import sys
from collections import deque
from collections import Counter
input = sys.stdin.readline
"""

"""
def is_Prime(n):
    isPrime = [1] * (n+1)
    isPrime[0] = isPrime[1] = 0

    for i in range(int(n**0.5)+1):
        if isPrime[i] == 1:
            for j in range(i*i, n+1, i):
                if isPrime[j] == 1:
                    isPrime[j] = i

    return isPrime

def solution():
   n = int(input())
   n_list = list(map(int, input().split()))
   prime_list = is_Prime(max(n_list))

   for i in n_list:
       while prime_list[i] != 1:
            print(prime_list[i], end=" ")
            i = i // prime_list[i]
       print(i)
solution()


# 시간 초과
import sys

input = sys.stdin.readline

N = int(input())
k = list(map(int, input().split()))

p = max(k)
isPrime = [1] * (p + 1)

for i in range(2, int(p**0.5) + 1):
  if isPrime[i] == 1:
    for j in range(i, p + 1, i):
      if isPrime[j] == 1:
        isPrime[j] = i

for n in k:
  stack = []
  while n != 1:
    stack.append(isPrime[n])
    n = n // isPrime[n]
  print(*stack)
  
# 시간초과

import sys

input = sys.stdin.readline

N = int(input())
k = list(map(int, input().split()))

p = max(k)
isPrime = [1] * (p + 1)

for i in range(2, int(p**0.5)):
  if isPrime[i] == 1:
    for j in range(i+i, p, i):
        isPrime[j] = i

print(isPrime)
for n in k:
  stack = []
  t = n
  while t > 1:
    d = isPrime[t]
    stack.append(d)
    t = t // d
  print(*stack)



# 시간초과 뜸
import sys
            
input = sys.stdin.readline

N = int(input())
k = list(map(int, input().split()))
N = max(k)

isPrime = [0] * (N + 1)

for i in range(2, N + 1):
  for j in range(i, N+1, i):
    if not isPrime[j]:
      isPrime[j] = i

for n in k:
  stack = []
  t = n
  while t!=1:
    d = isPrime[t]
    stack.append(d)
    t = t // d
  print(*stack)
  

