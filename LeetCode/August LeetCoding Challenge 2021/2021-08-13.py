class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        # 오름차순 정렬
        arr.sort()
        
        # key를 index로 뒀더니 time exceeded..!
        # 그럼 value를 key로 두자, value는 count, 위치는 몰라도 될듯
        cnt_dict = {}
        for i, v in enumerate(arr):
            if v in cnt_dict.keys():
                cnt_dict[v] += 1
            else:
                cnt_dict[v] = 1
        
        
        result = True
        for _, val in enumerate(arr):
            # 개수 안남았으면 패스
            if cnt_dict[val] == 0:
                continue
            # 짝 숫자 구하기
            findVal = val / 2 if val < 0 else val * 2
            # 짝 숫자 존재 여부 확인
            if findVal in cnt_dict.keys():
                if cnt_dict[findVal] == 0:
                    result = False
                    break
                else:
                    cnt_dict[findVal] -= 1
                    cnt_dict[val] -= 1
            else:
                result = False
                break
        return result
