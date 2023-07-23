logs = {}

def solution(id_list, report, k):
    answer = [0 for _ in range(len(id_list))]

    for id in id_list:
        logs[id] = set()
        
    for r in set(report): # 중복 신고 처리 위함
        user, abuser = r.split()
        logs[abuser].add(user)
    
    # 유저가 신고 메일 받은 횟수(신고한 사람(신고한 횟수 만큼) + 신고 받은 사람(1회))
    for abuser, users in logs.items():
        if len(users) >= k:
            for x in users:
                answer[id_list.index(x)] += 1
    return answer

######################
# 베스트 풀이

def solution(id_list, report, k):
    answer = [0] * len(id_list)    
    reports = {x : 0 for x in id_list} # 오..

    for r in set(report):
        reports[r.split()[1]] += 1

    for r in set(report):
        if reports[r.split()[1]] >= k:
            answer[id_list.index(r.split()[0])] += 1

    return answer
