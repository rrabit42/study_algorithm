import sys

input = sys.stdin.readline

N = int(input())
stack = []

for _ in range(N):
    arr = input().rstrip().split()
    if arr[0] == "push":
        stack.append(int(arr[1]))
    elif arr[0] == "pop":
        if len(stack) == 0:
            print(-1)
        else:
          top = stack.pop()
          print(top)
    elif arr[0] == "size":
        print(len(stack))
    elif arr[0] == "empty":
        if len(stack) == 0:
            print(1)
        else:
            print(0)
    elif arr[0] == "top":
      if len(stack) == 0:
        print(-1)
      else:  
        print(stack[-1])

        
# 한줄로 쓸 수 있다는거 잊음
# if stack, +(not stack) = +(True) = 0 + True = 0 + 1 = 1

stack = []
N = int(input())

for n in range(N):
    command = input().rstrip()
    if command == "pop":
        print(stack.pop() if stack else -1)
    elif command == "size":
        print(len(stack))
    elif command == "empty":
        print(+(not stack))
    elif command == "top":
        print(stack[-1] if stack else -1)
    else:
        _, x = command.split()
        stack.append(x)
