class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 앞에 있는 zero 수
        zero_cnt = 0
        for idx, num in enumerate(nums):
            if num == 0:
                zero_cnt += 1
            else:
                nums[idx - zero_cnt] = num
        
        for i in range(1, zero_cnt + 1):
            i *= -1
            nums[i] = 0
