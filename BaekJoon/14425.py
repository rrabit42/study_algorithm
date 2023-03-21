import sys

input = sys.stdin.readline

result = 0
N, M = map(int, input().split())

li = [input().rstrip() for _ in range(N)]

for _ in range(M):
    key = input().rstrip()
    for word in li:
        if word == key:
            result += 1
            break

print(result)

# 다른 풀이
# 이해가 필요해ㅋㅋ: https://stackoverflow.com/questions/1964934/what-does-contains-do-what-can-call-contains-function
# __contains__ 함수는 set에 있는 원소면 True 리턴
# map 함수의 반환값은 map 객체(iterable) -> 주로 list, set으로 바꿔서 사용: https://velog.io/@zbooster/map
import os
n,_,*s=os.read(0,os.fstat(0).st_size).split()
print(sum(map(set(s[:int(n)]).__contains__,s[int(n):])))

# 집합 S는 중복되는 값을 가지고 있지 않으니 set()으로 선언함
import sys

N, M = map(int, sys.stdin.readline().strip().split())
str = sys.stdin.read().split()
S, command = set(str[:N]), str[N:]
print(sum(1 for i in command if i in S))
