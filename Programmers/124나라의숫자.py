# 정답은 다 맞았으나, 효율성 테스트 하나도 통과 못함..ㅎㅎ
def solution(n):
    dp = ["1", "2", "4"] + ['' for i in range(n+1)]

    for i in range(3, n + 1):
        p, q = i//3 - 1, i % 3
        dp[i] = dp[p] + dp[q]

    return dp[n-1]

###################
# 재귀로 풀어도 안됨
def solution(n):
    dp = ["1", "2", "4"] + ['' for i in range(n+1)]
        
    # 전부 다 계산하지 말고, 관련 있는 숫자만 찾아 나가는 형식으로 바꿔야 할 듯
    def recur(i):
        if dp[i] != '':
            return dp[i]
        dp[i] = recur(i//3 - 1) + recur(i%3)
        return dp[i]
    recur(n-1)
        
    return dp[n-1]

##################
# 2진법 계산하는 느낌으로...(2진법도 몫, 나누기해서 반대로 하니까)
def solution(n):
    answer = ''
    dp = ["1", "2", "4"]
    
    while n:
        n -= 1
        answer = dp[n%3] + answer
        n //= 3
    
    return answer
##################
# 재귀도 가능은 합니다
def change124(n):
    if n<=3:
        return '124'[n-1] # 와우 이렇게 그냥 [] 안쓰고 index로...
    else:
        q, r = divmod(n-1, 3) # 0이 없기 때문에 기존 수에서 -1
        return change124(q) + '124'[r]
