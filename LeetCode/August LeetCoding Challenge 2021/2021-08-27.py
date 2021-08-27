class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        
        # 1 ~ 루트 c 까지
        for n in range(math.floor(math.sqrt(c)) + 1):
            left = c - n**2

            if math.floor(math.sqrt(left))**2 == left:
                return True
        return False
