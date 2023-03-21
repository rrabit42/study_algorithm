import sys

input = sys.stdin.readline

a, b = map(int, input().split(' '))

print(a+b)

# 한줄로 끝내기
print(sum(map(int,input().split())))
print(eval(input().replace(' ','+')))
