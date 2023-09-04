def solution(s):
    answer = -1

    stack = [s[0]]
    for i in s[1:]:
        if stack and stack[-1] == i:
            stack.pop()
            continue
        stack.append(i)
    
    answer = 1 if not stack else 0
    return answer

