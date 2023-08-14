# so easy..? Java로는 참 어렵게 풀었구나 싶음...
import sys
input = sys.stdin.readline

n = int(input())  # 1 <= n <= 50
# 100 이하 양수 + 0
a = list(map(int, input().split()))
b = list(map(int, input().split()))

# A에 있는 수만 재배열 -> 사실 둘 다 재배열해도 상관은 없음 -> A가 B 따라 움직이면 되긴 함
a.sort()
b.sort(reverse=True)
print(sum(a[i] * b[i] for i in range(n)))

#################################
# 이렇게까지 줄일 수 있다고..?
input()
print(sum([x*y for x,y in zip(sorted(map(int,input().split()),reverse=True),sorted(map(int,input().split())))]))
