class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        else:
            return -1

# 문제 의도는 이게 아니었을 것이다.
# 진짜 Binary Search로 풀면 아래와 같다. (내일 풀어야징)
