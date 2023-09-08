import sys

input = sys.stdin.readline

n, m = map(int, input().split())

pw_list = {}
for _ in range(n):
  site, pw = input().rstrip().split()
  pw_list[site] = pw

for _ in range(m):
  site = input().rstrip()
  print(pw_list[site])
