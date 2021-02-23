#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, cnt;
int print[8];

void input() {
	cin >> n >> m;
}

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", print[i]);
		}
		printf("\n");
		return;
	}

	// visited 검사 필요 없음!
	for (int i = 1; i <= n; i++) {
		print[cnt] = i;
		dfs(cnt + 1);
	}
}

void solution() {
	dfs(0);
}

int main() {
	input();
	solution();
}
