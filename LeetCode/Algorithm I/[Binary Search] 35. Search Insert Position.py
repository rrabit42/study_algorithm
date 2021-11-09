class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        # target이 없으면 target을 insert 했을 때의 index를 리턴해라
        # 오름차순, 중복 없음
        
        n = len(nums)
        left = 0
        right = n - 1
        
        # 예외처리
        if target < nums[left]:
            return left
        elif target > nums[right]:
            return right + 1
        
        # binary search
        while left < right:
            mid = (left + right) // 2
            
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid
            else:
                return mid
        
        return right
