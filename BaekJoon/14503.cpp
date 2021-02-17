#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX 50

using namespace std;

int n, m;
int r, c, d, nr, nc, nd;
int area[MAX][MAX]; // 0: 빈칸(청소X), 1: 벽, 2: 청소함
int result, cnt;

// ** switch로 했었는데 이걸 그냥 정해서 주는 것
// 북(0) 동(1) 남(2) 서(3) -> 인덱스로 방향 알 수 있게
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	// 세로크기 n, 가로크기 m
	cin >> n >> m;

	// 로봇청소기가 있는 칸 좌표(r, c), 바라보는 방향 d
	// 0: 북, 1: 동, 2: 남, 3: 서
	cin >> r >> c >> d;

	// 빈칸 0, 벽 1
	// 지도의 첫행, 마지막행, 첫열, 마지막열은 모두 벽
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> area[i][j];
		}
	}

	while (true) {
		// 1. 현재 위치 청소
		if (area[r][c] == 0) {
			area[r][c] = 2; // 청소
			result++;
		}

		// 2. 현재 방향 기준 왼쪽 방향부터 차례대로 탐색
			// 서-북-동-남 이 area에서도 동일(세로는 북->남, 가로는 동->서 이므로)
			// 즉, 왼쪽은 서로 3-2-1-0-3...
		bool flag = false; // 왼쪽 방향으로 전진 가능한지 여부
		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4;

			nr = r + dx[d];
			nc = c + dy[d];

		// - 왼쪽 청소 X: 그 방향으로 회전, 1칸 전진, 1번으로!
			if (area[nr][nc] == 0) {
				r = nr; c = nc;
				flag = true;
				break;
			}
		}

		// 전진했음. 1번으로 돌아가기
		if (flag) continue;

		// 4면이 모두 청소 불가일 때(벽 or 청소됨)
		// 후진 가능: 바라보는 방향 유지, 한칸 후진, 2번으로!(while 반복)
		nd = (d + 2) % 4; // 후진 방향
		r = r + dx[nd];
		c = c + dy[nd];

		// 후진 불가: 작동 불가
		if (area[r][c] == 1) break;
	}

	cout << result << '\n';
}

/*
 처음에 조건 4개를 따로 따로 구현하려 했는데
 가지치기 해서 조건을 파악해서 if else로 적절히 나누면 중복해서 하지 않아도 하나로 깔끔하게 동작 된다.
 여러모로 여러번 복습하면 좋을 문제인듯
*/
