class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # anagram을 묶어라!
        dict = {}
        for ele in strs:
            key = ''.join(sorted(ele))
            if key in dict.keys():
                dict[key].append(ele)
            else:
                dict[key] = [ele, ]
        result = []
        for _, groups in dict.items():
            result.append(groups)
        return result
        
