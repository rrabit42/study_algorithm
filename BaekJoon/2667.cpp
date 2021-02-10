#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX 25

using namespace std;

// 변수 선언
int n, num, cnt;
int arr[MAX][MAX] = {0, };
int visited[MAX][MAX] = {0, };
int direct[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int cnt_arr[1000];

void dfs(int row, int column) {

	visited[row][column] = 1;
	cnt++;

	int next_row, next_column;
	for (int i = 0; i < 4; i++) {
		next_row = row + direct[i][0];
		next_column = column + direct[i][1];
		
		// ** 좌표 조건 먼저 보고 continue, arr, visited 보는건 좀 시간이 걸리니까 그 이후에 하는 것도 시간을 줄일 수 있겠어!
		if (next_row >= 0 && next_row < n &&
			next_column >= 0 && next_column < n &&
			arr[next_row][next_column] &&
			!visited[next_row][next_column]) {

			dfs(next_row, next_column);
		}
	}
}

int main() {

	cin >> n;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j] - '0';	// ** 문자를 숫자로 바꾸는 방법
		}
	}

	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 방문한적 없고(0), 집이 있는 곳(1)일 때
			if (!visited[i][j] && arr[i][j]) {
				dfs(i, j);
				cnt_arr[index++] = cnt;	// ** vector를 사용했으면 됐을 듯!
				cnt = 0;
				num++;			// ** 그럼 num따로 안세고 vector.size()하면 됐음!
			}
		}
	}

	// 출력
	// 총 단지수
	cout << num << '\n';

	// 각 단지 내 집의 수(오름차순)
	sort(cnt_arr, cnt_arr + num);
	for (int i = 0; i < num; i++) {
		cout << cnt_arr[i] << '\n';
	}


	return 0;
}

/*
#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 25

int N;
int arr[MAX][MAX];
bool visit[MAX][MAX];
int house_cnt;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector <int> vec;

void DFS(int x, int y) {
	house_cnt++;
	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (arr[nx][ny] == 1 && visit[nx][ny] == false){
			DFS(nx, ny);
		}
	}
}

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++)	arr[i][j] = temp[j] - '0';
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				house_cnt = 0;
				DFS(i, j);
				vec.push_back(house_cnt);
			}
		}
	}

	sort(vec.begin(), vec.end());
	cout << vec.size() << endl;

	for (int i = 0; i < vec.size(); i++) cout << vec[i] << endl;

	return 0;
}
*/
