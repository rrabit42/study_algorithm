import math

N = int(input())  # 시험장 개수
A = map(int, input().split(' '))  # 각 시험장에 있는 응시자 수
B, C = map(int, input().split(' '))

result = N
for stu in A:
    stu = int(stu) - B
    if stu <= 0:
        continue
    result += math.ceil(stu / C)

print(result)
