def solution(scoville, K):
    answer = 0
    
    scoville.sort()
    if scoville[0] > K:
        return answer
    
    length = len(scoville)
    for i in range(length - 1):
        if scoville[i] < K:
            scoville[i + 1] = scoville[i] + scoville[i + 1] * 2
            answer += 1
            scoville.sort()
    
    if answer == 0 or scoville[length - 1] < K:
        answer = -1
    return answer
  
  # 테스트 케이스는 모두 통과했지만 효율성 테스트 모두 통과 못함 -> sort() 때문인듯
  # 좀 더 고민해보자
