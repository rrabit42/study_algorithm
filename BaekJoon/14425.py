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
