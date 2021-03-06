// 아 나 잘풀고 있었는데 꼬리 0으로 만드는거에서 막혀서... -> deque 쓰면 쉽구나...
// 인터넷 풀이에서 내 알고리즘 합쳐서 더 좋은 코드로 만듦!
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <deque>
#include <algorithm>
# define MAX 101

using namespace std;

int n, k, l;
int map[MAX][MAX];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

vector<pair<int, char>> v;

void input() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1; // 사과
	}

	cin >> l;
	for (int i = 0; i < l; i++) {
		int a;
		char b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
}

void solution() {
	deque<pair<int, int>> q;
	int x = 1, y = 1, d = 0, time = 0, idx = 0;

	// 뱀 위치
	q.push_back(make_pair(x, y));
	map[x][y] = 2;

	while (1) {
		time++;

		int nx = x + dx[d];
		int ny = y + dy[d];

		if ((nx <= 0 || ny <= 0 || nx > n || ny > n) || map[nx][ny] == 2) break;
		// 사과 없을 때
		else if (map[nx][ny] == 0) {
			map[nx][ny] = 2; // 머리 놓기
			map[q.back().first][q.back().second] = 0; // 꼬리 말기

			// 꼬리 갈 곳 저장
			q.pop_back();
			q.push_front(make_pair(nx, ny));
		}
		// 사과 있을 때
		else if (map[nx][ny] == 1) {
			map[nx][ny] = 2;
			q.push_front(make_pair(nx, ny));
		}

		if (idx < v.size()) {
			if (time == v[idx].first) {
				if (v[idx].second == 'L') d = (d + 3) % 4; // d++ 순환효과
				else if (v[idx].second == 'D') d = (d + 1) % 4; // d-- 순환 효과
				idx++;
			}
		}
		x = nx;
		y = ny;
	}
	cout << time << '\n';
}

int main() {
	input();
	solution();
}

/*
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
# define MAX 101

using namespace std;

int n, time = 0;
int length = 1;

int area[MAX][MAX] = { 0, };
int apple[MAX][MAX] = { 0, };
int direction[MAX][2] = { 0, };
int now_dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 오른쪽 진행에서 시계방향

void solution() {

	// 뱀이 이동할 좌표(머리좌표) 구하기
	int nx = 1, ny = 1;
	// 뱀의 꼬리 좌표
	int tx = 1, ty = 1;

	int i = 0, j = 0;

	while(true){
		time++;

		// 뱀의 방향 변환 정보(challenging)
		if (direction[i][0] == time) {
			if (direction[i][1] == 'L') j = (j + 3) % 4; // j++ 순환 효과
			else if (direction[i][1] = 'D') j = (j + 1) % 4; // j-- 순환 효과

			i++; // 다음 방향 정보로 넘어가기
		}

		// 뱀이 전진할 좌표(머리좌표)
		nx += now_dir[j][0];
		ny += now_dir[j][1];

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << area[i][j] << ' ';
			}
			cout << '\n';
		}
		// 벽 또는 자기자신의 몸과 부딪힘
		if ((nx == n) || (ny == n) || ( nx == 0) || ( ny == 0) || (area[nx][ny] == 3)) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cout << area[i][j] << ' ';
				}
				cout << '\n';
			}
			cout << time << '\n';
			return;
		}
		// 부딪히지 않음
		else {
			// 머리를 다음칸에 위치 시킴
			area[nx][ny] = 3;

			// 사과가 있다면
			if (apple[nx][ny] == 1) {
				apple[nx][ny] = 0;
				length++;
			}
			// 사과가 없다면
			else {
				// 몸 길이를 줄여서 꼬리가 위치한 칸 비우기
				area[tx][ty] = 0;
				// 꼬리가 몸통이 갔던 길 따라가야하는데..?
				tx += now_dir[j][0];
				ty += now_dir[j][1];
			}
		}
	}
}


void input() {
	int k, l, x;
	char c;

	cin >> n; // 입력 보드의 크기
	cin >> k; // 사과의 개수

	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b; // 사과의 위치
		apple[a][b] = 1;
	}

	cin >> l; // 뱀의 방향 변환 횟수
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		if (c == 'L') { // 왼쪽으로 90도 회전
			direction[i][0] = x;
			direction[i][1] = 1;
		}
		else if (c == 'D') { // 오른쪽으로 90도 회전
			direction[i][0] = x;
			direction[i][1] = 2;
		}
	}
}

int main() {
	input();
	area[1][1] = 3;
	solution();
}
*/
