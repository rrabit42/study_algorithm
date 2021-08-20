class Solution:
    def numDecodings(self, s: str) -> int:
        # 1개(1~9) 아니면 2개(10~26)
        # 동적프로그래밍 -> 재귀는 타임아웃
        
        # 처음이 0 이면 무조건 탈락
        if s[0] == "0":
            return 0
        
        dp = [0 for i in range(len(s) + 1)] # **자리수만큼 + 1
        
        # 글자 인덱스를 1~len(s)라고 생각
        new_s = "0" + s
        
        # 그 자리까지 오는데 해석할 수 있는 경우의 수
        dp[0] = 1 # 0이 아니니까 무조건 해석할 수 있음
        dp[1] = 1 # **idx-2를 해결하기 위함
        
        for idx in range(2, len(s) + 1):
            # 한자리 수 해석 -> 이전거의 연장선
            if 1 <= int(new_s[idx]) <= 9:
                dp[idx] += dp[idx-1]
            
            # 두자리수 해석 -> 그럼 전은 무조건 1자리로 해석해야함 그 경우의 수의 연장선이니까
            if 10 <= int(new_s[idx - 1 : idx + 1]) <= 26:
                dp[idx] += dp[idx-2] # 1일 때 -1... 맨 뒤 더함 => **첫 2자리면 +1 해줘야하는데
        
        return dp[len(s)]
