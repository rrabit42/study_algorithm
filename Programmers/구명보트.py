# 그리디 문제 + 투 포인터
# 한번에 풀려서 기분 좋았다! deque 쓸까 고민했지만 귀찮아서 그냥 투포인터로 품. 사실 투 포인터 의도한건 아니었는데 그렇게 풀게 됨! ㅎㅅㅎ

def solution(people, limit):
    boat = []
    people.sort()

    light = people[0]
    idx = 0
    
    for i in range(len(people)-1, -1, -1):
        if idx > i:
            break
        person = people[i]
        if person + light > limit:
            # 가장 가벼운 사람이랑도 못앉으면 혼자 가야지
            boat.append(person)
            continue
        # 가장 가벼운 사람이랑은 같이 앉아갈 수 있다! 그럼 앉아가슈
        if idx < i:
            boat.append(person + light)
            idx += 1
            light = people[idx]
            continue
        # 앉아갈 짝이 없으면 혼자 가렴
        boat.append(person)
    return len(boat)

######################
# 투 포인터
# 다른 사람들의 천재적인 풀이
def solution(people, limit) :
    answer = 0
    people.sort()

    a = 0
    b = len(people) - 1
    while a < b :
        if people[b] + people[a] <= limit :
            a += 1
            answer += 1
        b -= 1
    return len(people) - answer # 전체에서 두명이서 앉아가는 배의 숫자만큼을 빼줌
