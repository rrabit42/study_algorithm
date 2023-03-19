def solution(array, commands):
    answer = []
    
    for command in commands :
        i, j, k = command[0], command[1], command[2]
        subArr = array[i-1:j]
        subArr.sort()
        answer.append(subArr[k-1])
    
    return answer

# 더 pythonic 한 코드
def solution(array, commands):
    return [sorted(array[i-1:j])[k-1] for i,j,k in commands]
