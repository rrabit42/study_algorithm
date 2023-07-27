def solution(land):
    n = len(land)
    
    for i in range(1, n):
        for j in range(4):
            # 이전 행에서 선택 가능한 열
            t = land[i-1][:j]
            if j + 1 < 4:
                t += land[i-1][j+1:]
            
            land[i][j] += max(t)
    return max(land[n-1])
#######################
# 파이코닉하게 줄여 보았다
def solution(land):
    for i in range(1, len(land)):
        for j in range(len(land[0])):
            land[i][j] = max(land[i -1][: j] + land[i - 1][j + 1:]) + land[i][j] # j+1: !! :로 slicing하는건 out of index가 안나는군....

    return max(land[-1]) # 아 마지막은 그냥 -1 하면 되는데...
