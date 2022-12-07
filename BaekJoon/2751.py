import sys

n = int(input())
num = []
for _ in range(n):
    num.append(int(sys.stdin.readline())) # 예제의 최대값 1,000,000 이정도 까지 받게 되면 시간이 오래 걸림

num.sort()

for i in num:
    print(i)
    
'''
* 반복문으로 여러줄 입력받는 상황에서는 반드시 sys.stdin.readline()을 사용해야 시간초과가 발생하지 않습니다.

input() 내장 함수는 parameter로 prompt message를 받을 수 있다.
따라서 입력받기 전 prompt message를 출력해야 한다. 물론 prompt message가 없는 경우도 있지만, 이 경우도 약간의 부하로 작용할 수 있다.
하지만, sys.stdin.readline()은 prompt message를 인수로 받지 않는다.

또한, input() 내장 함수는 입력받은 값의 개행 문자를 삭제시켜서 리턴한다.
즉 입력받은 문자열에 rstrip() 함수를 적용시켜서 리턴한다.
반면에 sys.stdin.readline()은 개행 문자를 포함한 값을 리턴한다. 때문에 개행문자를 제거해야 합니다.
또한, 변수 타입이 문자열 형태(str)로 저장되기 때문에, 정수로 사용하기 위해서 형변환을 거쳐야 합니다.

참고 자료
https://buyandpray.tistory.com/7
https://velog.io/@yeseolee/Python-%ED%8C%8C%EC%9D%B4%EC%8D%AC-%EC%9E%85%EB%A0%A5-%EC%A0%95%EB%A6%ACsys.stdin.readline
'''
