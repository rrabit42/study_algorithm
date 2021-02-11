#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#define MAX 101

using namespace std;

// (0,0) ~ (n,m) n이 x, m이 y
// k개의 직사각형
int m, n, k, cnt;
int arr[MAX][MAX] = { 0, };
int visited[MAX][MAX] = { 0, };
int direct[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<int> v;

// 입력 받은 좌표로 직사각형 그리기(1로 채우기)
// (x1, y1) ~ (x2-1, y2-1)
void draw_rec(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			arr[i][j] = 1;
		}
	}
}

void dfs(int x, int y) {

	visited[x][y] = 1;
	cnt++;

	int n_x, n_y;
	for (int i = 0; i < 4; i++) {
		n_x = x + direct[i][0];
		n_y = y + direct[i][1];
		
		// 좌표가 범위를 넘어 갔을 때
		if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= m) continue;
		// 방문한적 없고(0), 직사각형이 아닌 빈 영역(0)일 때
		if (!visited[n_x][n_y] && !arr[n_x][n_y]) {
			dfs(n_x, n_y);
		}
	}
}

int main() {
	cin >> m >> n >> k;
	
	int x1, y1, x2, y2;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1>> x2 >> y2;
		draw_rec(x1, y1, x2, y2);
	}

	// (0,0) ~ (n,m) n이 x, m이 y
	// 실제로 배열에 그려지는건 (0,0)~(n-1, m-1)
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[j][i] && !arr[j][i]) {
				dfs(j, i);
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}

	// 출력
	// 분리 되어 나누어지는 영역 개수
	cout << v.size() << '\n';
	// 각 영역의 넓이 오름차순
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
}
