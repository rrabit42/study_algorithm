// BFS 방법!!
#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>
#define MAX 100

using namespace std;


int n, nor_cnt = 0, rg_cnt = 0;
int nor_arr[MAX][MAX], rg_arr[MAX][MAX];
int direct[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
bool visited[MAX][MAX]; // 0, 즉, false로 초기화 되어있음
queue<pair<int, int>> q;


void BFS(int row, int column, int(*arr)[MAX]) {
	
	int color = arr[row][column]; // 해당 색

	q.push(make_pair(row, column));
	visited[row][column] = 1;

	while (!q.empty()) {

		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {

			int next_row = now.first + direct[i][0];
			int next_column = now.second + direct[i][1];

			// 범위를 벗어난 좌표
			if (next_row<0 || next_row>=n || next_column<0 || next_column >=n) {
				continue;
			}

			// 같은 (색)구역 모두 찾고 ** 모두 visited로 바꿈!!
			if (color == arr[next_row][next_column] & !visited[next_row][next_column]) {
				visited[next_row][next_column] = 1;
				q.push(make_pair(next_row, next_column));
			}
		}
	}
}

int main() {
	
	cin >> n;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			switch (str[j])
			{
			case 'R':
				nor_arr[i][j] = 1;
				rg_arr[i][j] = 1;
				break;
			case 'G':
				nor_arr[i][j] = 2;
				rg_arr[i][j] = 1;
				break;
			case 'B':
				nor_arr[i][j] = 3;
				rg_arr[i][j] = 3;
				break;
			}
		}
	}

	// BFS
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				BFS(i, j, nor_arr);
				nor_cnt++; // 한 구역 다 셈!
			}
		}
	}
	
	// 초기화 후 사용
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				BFS(i, j, rg_arr);
				rg_cnt++; // 한 구역 다 셈!
			}
		}
	}

	cout << nor_cnt << ' ' << rg_cnt << '\n';
}

// DFS 방법

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>

using namespace std;

// 일단 문제 이해가 잘 안됨ㅋㅋ -> R와 G를 구분 못한다는 소리였다!

/*
#define MAX 100
int n;
int nor_arr[MAX][MAX];
int rg_arr[MAX][MAX];
int visited[MAX][MAX]; // 0으로 초기화
queue<pair<int, int>> q;
int nor_cnt = 0, rg_cnt = 0;
int direct[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

// 1. 언제 구역 더하기를 해야 하는가
void BFS(int row, int column, int (*arr)[MAX]) {

	q.push(make_pair(row, column));

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		int color = arr[now.first][now.second];

		// queue안에 들어는 갔지만 이미 탐색이 끝난 경우
		if (visited[now.first][now.second] == 1) continue;

		visited[row][column] = 1;

		for (int i = 0; i < 4; i++) {
			int next_row = now.first + direct[i][0];
			int next_column = now.second + direct[i][1];

			// 범위를 벗어난 좌표, 이미 탐색이 끝난 좌표
			if (next_row<0 || next_row>n || next_column<0 || next_column >n || visited[next_row][next_column] == 1) {
				continue;
			}

			// 같은 (색)구역 모두 찾고
			if (color == arr[next_row][next_column]) {
				visited[next_row][next_column] = 1;
			}

			// 다른 구역으로 넘어가기
			else {
				q.push(make_pair(next_row, next_column));
			}
		}
		nor_cnt += 1;
	}
}
*/

int n, nor_cnt = 0, rg_cnt = 0;
// 이렇게 하니까 메모리 초과남
// int nor_arr[MAX][MAX];
// int rg_arr[MAX][MAX];

// ** BFS로는 어려워서 라업보고 DFS로,,!ㅜㅜ
// 나중에는 혼자서 풀고 싶다,,
void DFS(int **arr, int num, int x, int y) {
	arr[y][x] = 0;	// visited 표시?
	if (y > 0 && arr[y - 1][x] == num)
		DFS(arr, num, x, y - 1);
	if (y < n - 1 && arr[y + 1][x] == num) // n-1 해야 y+1이 index 범위에서 벗어나지 않으니까
		DFS(arr, num, x, y + 1);
	if (x > 0 && arr[y][x - 1] == num)
		DFS(arr, num, x - 1, y);
	if (x < n - 1 && arr[y][x + 1] == num)
		DFS(arr, num, x + 1, y);
}

int main() {
	cin >> n;

	// ** whitespace로 구분하는데 애초에 문자열로 들어옴... 와 이걸 몰랐네
	string str;
	int **nor_arr = new int*[n], **rg_arr = new int*[n];

	for (int i = 0; i < n; i++) {
		nor_arr[i] = new int[n];
		rg_arr[i] = new int[n];
	}

	// ** 색깔 단어 그대로 안받고 숫자로 바꿈
	// ** 그럼 적록색맹은 그냥 R과 G를 같은 숫자로 표기하면 됨!!
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			switch (str[j])
			{
			case 'R':
				nor_arr[i][j] = 1;
				rg_arr[i][j] = 1;
				break;
			case 'G':
				nor_arr[i][j] = 2;
				rg_arr[i][j] = 1;
				break;
			case 'B':
				nor_arr[i][j] = 3;
				rg_arr[i][j] = 3;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (nor_arr[i][j] != 0) {
				nor_cnt++;
				DFS(nor_arr, nor_arr[i][j], j, i);
			}
			if (rg_arr[i][j] != 0) {
				rg_cnt++;
				DFS(rg_arr, rg_arr[i][j], j, i);
			}
		}
	}

	cout << nor_cnt << ' ' << rg_cnt << '\n';
	return 0;
}
