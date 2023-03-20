N = int(input())
nums = map(int, input().split(' ')) # split 디폴트가 공백이라 그냥 .split() 해도 됨
numSet = set()

for i in nums:
    numSet.add(i)

for i in sorted(numSet):
  print(i, end=' ')
  
# 순회로 출력하지 말고 아래와 같이 출력도 가능
print(*sorted(numSet)) 
