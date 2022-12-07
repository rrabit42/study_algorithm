import sys

N = int(input())

result = N
for _ in range(N):
    word = sys.stdin.readline().strip('\n')
    for i in range(len(word) - 1):
        if word[i] != word[i + 1]:
            if word.count(word[i], i + 1) > 0:
                result -= 1
                break

print(result)
