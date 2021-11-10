class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 오른쪽방향으로 rotate
        # 그냥 Index를 바꿔주면 되지
        ## 주의할점: In-place 방식으로 nums를 바꿔야함!
        n = len(nums)
        res = nums.copy()
        
        for idx, i in enumerate(res):
            idx = (idx + k) % n
            nums[idx] = i
            
