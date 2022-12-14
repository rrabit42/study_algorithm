def solution(arr):
    answer = []
    answer.append(arr[0])
    for i in range(1, len(arr)):
        if arr[i - 1] != arr[i]:
            answer.append(arr[i])
    
    return answer


# 다른 사람 풀이
# a[-1:]를 빈 배열에 써도 문제가 없다!
def no_continuous(s):
    a = []
    for i in s:
        if a[-1:] == [i]: continue
        a.append(i)
    return a
