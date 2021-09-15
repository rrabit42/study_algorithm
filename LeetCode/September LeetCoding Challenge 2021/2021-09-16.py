class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        # 현재 숫자가 더 크면 + 1(>), 다음 숫자가 더 크면 -1(<)
        flip = 0
        
        result, cnt = 1, 1
        for idx in range(len(arr) - 1):
            if flip <= 0 and arr[idx] > arr[idx+1]:
                flip = 1
                cnt += 1
            elif flip >= 0 and arr[idx] < arr[idx+1]:
                flip = -1
                cnt += 1
            # 조건에 맞지 않을 때
            else:
                if arr[idx] == arr[idx+1]:
                    flip = 0
                result = max(result, cnt)
                cnt = 2 if flip != 0 else 1
        
        result = max(result, cnt)
        return result
