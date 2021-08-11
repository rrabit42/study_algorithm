class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        # 0들 나오고 그 후에 1들 나오게 만들라는 소리인듯
        # 그리디 알고리즘
        
        zeroCnt, oneCnt = 0, 0
        
        for i in range(len(s)):
            if s[i] == "0":
                zeroCnt += 1
            else:
                oneCnt += 1
            zeroCnt = min(zeroCnt, oneCnt) # 뒤집어야할 0의 개수
        
        return min(zeroCnt, oneCnt) # 0과 1 중 적은 것을 flip
