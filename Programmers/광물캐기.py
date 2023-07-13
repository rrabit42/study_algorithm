from collections import deque

relations = {
    "diamond": [1, 5, 25], # 다이아, 철, 돌 곡괭이 순
    "iron": [1, 1, 5],
    "stone": [1, 1, 1],
}

def solution(picks, minerals):
    answer = 25 * 50
    
    # 캘 수 있는 최대 광물 수
    max_minerals = sum(picks) * 5
    if len(minerals) > max_minerals:
        minerals = minerals[:max_minerals]
    
    q = deque()
    
    # 현재 총 곡괭이 수, 선택한 곡괭이, 캔 광물의 수, 현재 피로도
    q.append((picks, 0, 0, 0))

    while q:
        cur_picks, cur_pick, n, piro = q.pop()
        
        # 곡괭이를 다 썼거나(*cur_pick 횟수 남았는데 sum 0일 수 있음), 모든 광물을 다 캤을 경우
        if (sum(cur_picks) == 0 and n % 5 == 0) or n == len(minerals):
            answer = min(answer, piro)
            continue
        
        # 캘 광물
        rock = minerals[n]
        
        # 새 곡괭이 선택
        if n % 5 == 0:
            for next_pick, cnt in enumerate(cur_picks):
                if cnt != 0:
                    next_picks = cur_picks.copy()
                    next_picks[next_pick] -= 1
                    q.append((next_picks, next_pick, n + 1, piro + relations[rock][next_pick]))
        # 곡괭이 계속 사용
        else:
            q.append((cur_picks, cur_pick, n + 1, piro + relations[rock][cur_pick]))

    return answer


##############################
# 백트래킹 이라고 보기에는 뭐하지만,, 그냥 재귀 아닐까?
relations = {
    "diamond": [1, 5, 25], # 다이아, 철, 돌 곡괭이 순
    "iron": [1, 1, 5],
    "stone": [1, 1, 1],
}

def solution(picks, minerals):
    answer = 25 * 50
    
    # 캘 수 있는 최대 광물 수
    max_minerals = sum(picks) * 5
    if len(minerals) > max_minerals:
        minerals = minerals[:max_minerals]
    
    # 현재 총 곡괭이 수, 선택한 곡괭이, 캔 광물의 수, 현재 피로도
    def backtracking(picks, pick, n, piro):
        nonlocal answer
        # 곡괭이를 다 썼거나(*cur_pick 횟수 남았는데 sum 0일 수 있음), 모든 광물을 다 캤을 경우
        if (sum(picks) == 0 and n % 5 == 0) or n == len(minerals):
            answer = min(answer, piro)
            return
        
        # 캘 광물
        rock = minerals[n]
        
        # 새 곡괭이 선택
        if n % 5 == 0:
            for next_pick, cnt in enumerate(picks):
                if cnt != 0:
                    next_picks = picks.copy()
                    next_picks[next_pick] -= 1
                    backtracking(next_picks, next_pick, n + 1, piro + relations[rock][next_pick])
        # 곡괭이 계속 사용
        else:
            backtracking(picks, pick, n + 1, piro + relations[rock][pick])
    
    backtracking(picks, 0, 0, 0)
    return answer
