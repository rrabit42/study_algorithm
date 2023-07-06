from collections import deque

# keypad = [
#     ['1', '2', '3'],
#     ['4', '5', '6'],
#     ['7', '8', '9'],
#     ['*', '0', '#']
# ]
# keypad = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '0', '#']
keypad = {
    1: [0,0], 2: [0,1], 3: [0,2],
    4: [1,0], 5: [1,1], 6: [1,2],
    7: [2,0], 8: [2,1], 9: [2,2],
    "*": [3,0], 0: [3,1], "#": [3,2]
}

# visited는 필요 없음. 현재 손가락의 위치만 알고 있으면 됨
# 숫자만 입력

def solution(numbers, hand):
    answer = ''
    left = deque(['*'])
    right = deque(['#'])
    
    act = ''
    for num in numbers:
        if num in [1, 4, 7]:
            act = 'left'
        elif num in [3, 6, 9]:
            act = 'right'
        else: # 2, 5, 8, 0
            # 좌표 거리 계산
            x, y = keypad[num]
            lx, ly = keypad[left[0]]
            rx, ry = keypad[right[0]]
            left_dis = abs(lx - x) + abs(ly - y)
            right_dis = abs(rx - x) + abs(ry - y)
            
            # L과 가까운 경우
            if left_dis < right_dis:
                act = 'left'
            # R과 가까운 경우
            elif right_dis < left_dis:
                act = 'right'
            # 동일한 거리인 경우
            else:
                act = hand

        # 선택한 손에 맞는 행동하기
        if act == 'left':
            answer += 'L'
            left.pop()
            left.append(num)
        else:
            answer += 'R'
            right.pop()
            right.append(num)
        
    return answer

############################
# 굳이 deque 쓸 필요 없음
keypad = {
    1: [0,0], 2: [0,1], 3: [0,2],
    4: [1,0], 5: [1,1], 6: [1,2],
    7: [2,0], 8: [2,1], 9: [2,2],
    "*": [3,0], 0: [3,1], "#": [3,2]
}

def solution(numbers, hand):
    answer = ''
    left = '*'
    right = '#'
    
    act = ''
    for num in numbers:
        if num in [1, 4, 7]:
            act = 'left'
        elif num in [3, 6, 9]:
            act = 'right'
        else: # 2, 5, 8, 0
            # 좌표 거리 계산
            x, y = keypad[num]
            lx, ly = keypad[left]
            rx, ry = keypad[right]
            left_dis = abs(lx - x) + abs(ly - y)
            right_dis = abs(rx - x) + abs(ry - y)
            
            # L과 가까운 경우
            if left_dis < right_dis:
                act = 'left'
            # R과 가까운 경우
            elif right_dis < left_dis:
                act = 'right'
            # 동일한 거리인 경우
            else:
                act = hand

        # 선택한 손에 맞는 행동하기
        if act == 'left':
            answer += 'L'
            left = num
        else:
            answer += 'R'
            right = num
        
    return answer
