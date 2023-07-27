def solution(land):
    n = len(land)
    
    for i in range(1, n):
        for j in range(4):
            t = land[i-1][:j]
            if j + 1 < 4:
                t += land[i-1][j+1:]
            
            land[i][j] += max(t)
    return max(land[n-1])
