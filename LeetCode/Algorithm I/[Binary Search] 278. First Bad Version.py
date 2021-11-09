# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        # Bad가 정해져있고 n은 전체 버전
        # binary search로 좁혀나가기
        
        begin = 0   # 1로하면 테스트케이스 (1,1) 일 때 에러
        end = n
        while(begin + 1 != end):
            mid_v = (begin + end) // 2
            result = isBadVersion(mid_v)
            if result:
                end = mid_v
            else:
                begin = mid_v
        
        return end
