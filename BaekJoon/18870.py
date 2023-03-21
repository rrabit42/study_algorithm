import sys

input = sys.stdin.readline

N = int(input())
cors = list(map(int, input().split()))

order = {c: i for i, c in enumerate(sorted(set(cors)))}

print(*[order[i] for i in cors])
