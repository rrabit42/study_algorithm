#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1001	// 입력에서 N이 1<=N<=1000

int n, m, start;	// n: 정점의 개수, m: 간선의 개수, start: 시작할 정점의 번호
int A[MAX][MAX];	// 인접행렬의 값을 받기 위한 행렬
int visit[MAX];		// 방문했던 것을 체크하기 위한 플래그 배열, dfs에서 방문 시 1/미방문 0
					// bfs에서는 썼던거 visit배열 그대로 사용하려하니까 반대로 사용


void dfs(int start) {
	cout << start << ' ';	// 첫 start 정점 번호 출력
	visit[start] = 1;	// 방문하였으므로
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 1 || A[start][i] == 0)
			continue;
		dfs(i);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = 0;	// dfs에서 사용한 visit 배열을 반대로 사용하면 됨

	while (!q.empty()) {
		start = q.front();
		cout << start << ' ';
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (A[start][i] == 0 || visit[i] == 0)
				continue;
			q.push(i);
			visit[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m >> start;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		A[x][y] = A[y][x] = 1;	// [1][2]의 인접행렬의 값은 [2][1]과 같기 때문
	}
	dfs(start);
	cout << endl;
	bfs(start);
	return 0;
}
