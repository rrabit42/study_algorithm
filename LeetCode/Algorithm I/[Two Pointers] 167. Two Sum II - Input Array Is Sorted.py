class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        result = []
        
        i, j = 0, len(numbers) - 1
        
        while i < j :
            guess = numbers[i] + numbers[j]
            
            if guess == target:
                break
            elif guess < target:
                i += 1
            else:
                j -= 1
        
        return [i+1, j+1]
