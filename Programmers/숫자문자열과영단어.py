def solution(s):
    answer = ""
    numDic = {
        "ze": ["0", 4],
        "on": ["1", 3],
        "tw": ["2", 3],
        "th": ["3", 5],
        "fo": ["4", 4],
        "fi": ["5", 4],
        "si": ["6", 3],
        "se": ["7", 5],
        "ei": ["8", 5],
        "ni": ["9", 4]
    }
    
    if s.isdigit():
        answer = s
    else:
        index = 0
        while(index < len(s)):
            l = s[index]
            if l.isdigit():
                answer += str(l)
                index += 1
            else:
                l = s[index: index+2]
                answer += numDic[l][0]
                index += numDic[l][1]

    answer = int(answer)
    return answer

# replace 사용

2
3
4
5
6
7
8
num_dic = {"zero":"0", "one":"1", "two":"2", "three":"3", "four":"4", "five":"5", "six":"6", "seven":"7", "eight":"8", "nine":"9"}

def solution(s):
    answer = s
    for key, value in num_dic.items():
        answer = answer.replace(key, value)
    return int(answer)
