class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        n1 = num1.split('+')
        n2 = num2.split('+')
        
        n1_r = int(n1[0])
        n1_i = int(n1[1][:-1])
        n2_r = int(n2[0])
        n2_i = int(n2[1][:-1])
        real = (n1_r * n2_r) - (n1_i * n2_i)
        imag = (n1_i * n2_r) + (n2_i * n1_r)
        
        # 실수부 + 허수부
        return f"{real}+{imag}i"
        
##################################
# 더 정돈시켜보았다
class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        n1 = num1.replace('i', '').split('+')
        n2 = num2.replace('i', '').split('+')
        
        real = (int(n1[0]) * int(n2[0])) - (int(n1[1]) * int(n2[1]))
        imag = (int(n1[1]) * int(n2[0])) + (int(n2[1]) * int(n1[0]))
        
        # 실수부 + 허수부
        return f"{real}+{imag}i"
