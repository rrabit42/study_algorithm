#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
#define MAX 8

int map[MAX][MAX];
queue<pair<int, int>> q;
vector<pair<int, int>> virus;
int direct[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int safe_area, bfs_area, max_area;
int n, m;

// 바이러스의 위치(x1, y1)
void BFS(int x1, int y1, bool visited[][MAX]) {
	bfs_area = 0;

	visited[y1][x1] = true;
	q.push(make_pair(x1, y1));

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		// 바이러스로부터 4방향 탐색(전이)
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = make_pair(now.first + direct[i][0], now.second + direct[i][1]);
			// 바이러스가 전이될 수 있는 곳인지 판단
			if (next.first < m && next.first >= 0 && next.second < n&&next.second >= 0 && !visited[next.second][next.first] && map[next.second][next.first] == 0) {
				q.push(next);
				visited[next.second][next.first] = true;
				bfs_area++; // 전이된 지역 +1
			}
		}
	}
}

void DFS(int cnt, int x, int y) {
	// 벽이 3군데 세워졌을 때
	if (cnt == 3) {
		int area = safe_area - 3; // 벽이 세워진 영역 빼기
		bool visited[MAX][MAX] = { 0, };
		for (int i = 0; i < virus.size(); i++) {
			BFS(virus[i].first, virus[i].second, visited);
			area -= bfs_area;	// 전이된 지역을 안전 지역에서 빼기
		}
		if (max_area < area)
			max_area = area;
	}

	// 가로 끝까지 갔을 때
	if (x >= m) {
		x = 0;
		y++;
	}

	// 세로 끝까지 갔을 때
	if (y >= n)
		return;

	// 벽 세우기
	if (map[y][x] == 0) {
		map[y][x] = 1;
		DFS(cnt + 1, x + 1, y); // 벽을 추가로 세우고 다시 탐색
		map[y][x] = 0;			// 벽 제거
	}

	// 그 다음 좌표에 벽세우기
	DFS(cnt, x + 1, y);
}

int main() {
	
	// 지도의 세로크기 N, 가로크기 M
	cin >> n >> m;

	// 지도 모양 입력 받기
	// 0: 빈칸, 1: 벽, 2: 바이러스
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				safe_area++;
			if (map[i][j] == 2)
				virus.push_back(make_pair(j, i));
		}
	}

	DFS(0, 0, 0);
	cout << max_area << endl;
}
