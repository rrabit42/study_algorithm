class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.sumN = {-1: 0}
        

    def sumRange(self, left: int, right: int) -> int:
        # 메모이제이션
        
        def check(idx) -> int:
            if idx == 0:
                self.sumN[idx] = self.nums[idx]
            
            if idx in self.sumN.keys():
                return self.sumN[idx]
            else:
                self.sumN[idx] = check(idx -1) + self.nums[idx]    
            return self.sumN[idx]
        
        check(right)

        return self.sumN[right] - self.sumN[left-1]
        
########################
# 초기 코드
class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums
        

    def sumRange(self, left: int, right: int) -> int:
        sum = 0
        for i in range(left, right+1):
            sum += self.nums[i]
        return sum
