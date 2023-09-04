import math

def solution(progresses, speeds):
    answer = []
    
    # 작업 시간 배열
    works = []
    for i in range(len(progresses)):
        work = math.ceil((100 - progresses[i]) / speeds[i])
        works.append(work)
    
    # 자기 이전 중 큰 친구와 같이 간다.
    # 자기보다 작은애 만나면 answer 기록
    # 반례: works = [5, 3, 4] 일 경우 [1]
    big = works[0]
    cnt = 1
    for i in range(1, len(progresses)):
        if works[i] <= big:
            cnt += 1
        else:
            answer.append(cnt)
            big = works[i]
            cnt = 1
    answer.append(cnt)
    return answer

###################################
# zip을 쓰면 for문을 두번 돌 필요가 없다
def solution(progresses, speeds):
    Q=[]
    for p, s in zip(progresses, speeds):
        if len(Q)==0 or Q[-1][0]<-((p-100)//s):
            Q.append([-((p-100)//s),1])
        else:
            Q[-1][1]+=1
    return [q[1] for q in Q]
#################################
# index 에러를 이용한 풀이
from math import ceil

def solution(progresses, speeds):
    daysLeft = list(map(lambda x: (ceil((100 - progresses[x]) / speeds[x])), range(len(progresses))))
    count = 1
    retList = []

    for i in range(len(daysLeft)):
        try:
            if daysLeft[i] < daysLeft[i + 1]:
                retList.append(count)
                count = 1
            else:
                daysLeft[i + 1] = daysLeft[i]
                count += 1
        except IndexError:
            retList.append(count)

    return retList
