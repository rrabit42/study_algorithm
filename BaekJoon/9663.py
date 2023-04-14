import sys
input = sys.stdin.readline

n = int(input())

# 놓을 수 있으면 1(true)
check_col = [True for _ in range(n)]
check_left = [True for _ in range(n * 2)]  # 왼쪽 대각선 공통점: i+j 의 값이 같다
check_right = [True for _ in range(n * 2)]  # 오른쪽 대각선 공통점: abs(i-j) 값이 같다
cnt = 0

def backtracking(queen):
    if queen == n:
      global cnt
      cnt += 1
      return cnt

    # 가로에는 어차피 한개 밖에 올 수 없고, 각 가로는 무조건 퀸이 1개 있으므로
    # 퀸의 자리는 (queen, i), 윗줄부터 놓고 아랫줄로 온다!
    for i in range(n):
        # 퀸을 놓을 수 있는 자리인지 확인한다
        if check_col[i] and check_left[queen + i] and check_right[queen -i + n]:
            # 퀸을 i 자리에 놓는다
            check_col[i] = False
            check_left[queen + i] = False
            check_right[queen -i + n] = False
            backtracking(queen + 1)  # 다음 퀸 호출
            # 리셋
            check_col[i] = True
            check_left[queen + i] = True
            check_right[queen -i + n] = True

backtracking(0)
print(cnt)
