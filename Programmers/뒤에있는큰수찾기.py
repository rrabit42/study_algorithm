def solution(numbers):
    answer = [-1]
    stack = [numbers[-1]]
    
    for i in range(len(numbers)-2, -1, -1):
        while stack and stack[-1] <= numbers[i]: # 같아도 pop
            stack.pop()
        
        if stack:
            answer.append(stack[-1])
        else:
            answer.append(-1)
            stack.append(numbers[i])
        
        if numbers[i] > numbers[i-1]:
            stack.append(numbers[i])
    
    answer.reverse()
    return answer

###################
# 백준 탑 풀이 그대로 써도 성공
# index 활용
def solution(numbers):
    n = len(numbers)
    stack = [] # idx 스택
    answer = [-1] * n
    
    for i in range(n):
        while stack and numbers[i] > numbers[stack[-1]]:
            idx = stack.pop()
            answer[idx] = numbers[i]
        stack.append(i)
    return answer
