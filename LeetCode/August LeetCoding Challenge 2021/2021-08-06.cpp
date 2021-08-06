from functools import lru_cache # 솔루션 참고ㅋㅋㅋ

class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        # 먼저 시작하는 사람이 이길 수 있으면 true 리턴

        # Dp-Top Down => python에서는 시간복잡도 문제 발생 가능 아악
        @lru_cache(None)
        def dp(begin: int, end: int):
            if begin > end:
                return 0
            
            # 누구 차례인지 게산
            alex_turn = ((begin + end) % 2 == 0)
            
            if alex_turn:
                # 여기서 무조건 끝남
                return max(piles[begin] + dp(begin + 1, end), piles[end] + dp(begin, end-1))
            else:
                # lee가 선택한건 빼야지!!!!!! 그래서 0보다 큰지 작은지
                return max(-piles[begin] + dp(begin + 1, end), -piles[end] + dp(begin, end-1))
                # return min(-piles[begin] + dp(begin + 1, end), -piles[end] + dp(begin, end-1))
        
        return dp(0, len(piles)-1) > 0

# 수학적으로는 항상 True를 리턴하면 된다고 한다.
