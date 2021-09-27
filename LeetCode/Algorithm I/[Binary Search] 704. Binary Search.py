class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        else:
            return -1

# 문제 의도는 이게 아니었을 것이다.
# 진짜 Binary Search로 풀면 아래와 같다.
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # nums는 오름차순으로 정렬되어 있음
        
        left = 0
        right = len(nums) - 1
        
        while(left <= right):
            mid = (left + right) // 2

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        
        return -1
            
