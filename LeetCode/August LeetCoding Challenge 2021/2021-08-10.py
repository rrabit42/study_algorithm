class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        result = ""
        
        n1 = len(num1)
        n2 = len(num2)
        
        up = 0
        if(n1 >= n2):
            for i in range(-1, -n2-1, -1):
                cal = str(int(num1[i]) + int(num2[i]) + up)
                result = cal[-1] + result
                up = int(cal[0]) if len(cal) >= 2 else 0
            # 나머지는 바로 붙여주기
            for i in range(-n2-1, -n1-1, -1):
                cal = str(up + int(num1[i]))
                result = cal[-1] + result
                up = int(cal[0]) if len(cal) >= 2 else 0
                
        else:
            for i in range(-1, -n1-1, -1):
                cal = str(int(num1[i]) + int(num2[i]) + up)
                result = cal[-1] + result
                up = int(cal[0]) if len(cal) >= 2 else 0
            # 나머지는 바로 붙여주기
            for i in range(-n1-1, -n2-1, -1):
                cal = str(up + int(num2[i]))
                result = cal[-1] + result
                up = int(cal[0]) if len(cal) >= 2 else 0
        
        if up != 0:
            result = str(up) + result
        
        return result
###########################################################

class Solution:
    def str_calculate(self, big_len: int, small_len: int, big_str: str, samll_str: str):
        up = 0
        result = ""
        # 겹치는 자리수는 계산해주고
        for i in range(-1, -small_len-1, -1):
            cal = str(int(big_str[i]) + int(samll_str[i]) + up)
            result = cal[-1] + result
            up = int(cal[0]) if len(cal) >= 2 else 0
        # 나머지 숫자 붙여주기
        for i in range(-small_len-1, -big_len-1, -1):
            cal = str(up + int(big_str[i]))
            result = cal[-1] + result
            up = int(cal[0]) if len(cal) >= 2 else 0
        # 자리수 넘친거 있는지 확인
        if up != 0:
            result = str(up) + result
        return result
        
    def addStrings(self, num1: str, num2: str) -> str:
        n1 = len(num1)
        n2 = len(num2)
        
        if(n1 >= n2):
            result = self.str_calculate(n1, n2, num1, num2)
        else:
            result = self.str_calculate(n2, n1, num2, num1)
        
        return result
