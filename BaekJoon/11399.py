import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

# 시간 적게 걸리는 사람이 앞에 오는게 맞음
arr.sort()
for i in range(1, n):
  arr[i] += arr[i-1]
  
print(sum(arr))
