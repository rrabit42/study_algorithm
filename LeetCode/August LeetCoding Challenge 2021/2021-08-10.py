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
