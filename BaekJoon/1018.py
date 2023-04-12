import sys

input = sys.stdin.readline

n, m = map(int, input().split())

board = []
for _ in range(n):
    row = input().rstrip()
    list = []
    for r in row:
        list.append(r)
    board.append(list)

# (i, j) 시작좌표
min_cnt = 64
for b in ['B', 'W']:
    for i in range(0, n - 7):
        for j in range(0, m - 7):
            cnt = 0
            for k in range(8):
                for l in range(8):
                    # print(f'{i + k} {j + l} {board[i + k][j + l]} {b}')
                    if board[i + k][j + l] != b:
                        cnt += 1
                    b = 'W' if b == 'B' else 'B'
                b = 'W' if b == 'B' else 'B'
            # min_cnt = min(cnt, min_cnt) 이렇게 하면 더 짧아질듯!
            if cnt < min_cnt:
                min_cnt = cnt

print(min_cnt)
  
