class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        # non-decreasing order -> 리스트에 같은 숫자가 존재
        squared = [i*i for i in nums]
        squared.sort()
        
        return squared
