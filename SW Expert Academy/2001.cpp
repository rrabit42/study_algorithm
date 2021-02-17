#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX 15

using namespace std;

int t, n, m, result;
int fly[MAX][MAX] = {0, };

// dfs
int catch_flies(int row, int col) {
	int sum = 0;
	for (int i = row; i < row + m; i++) {
		for (int j = col; j < col + m; j++) {
			sum += fly[i][j];
		}
	}
	return sum;
}


int main() {
	cin >> t;

	for (int test_case = 1; test_case <= t; test_case++) {
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> fly[i][j];
			}
		}

		// fly 잡기
		for (int i = 0; i <= n - m; i++) {
			for (int j = 0; j <= n - m; j++) {
				result = max(result, catch_flies(i,j));
			}
		}

		cout << '#' << test_case << ' ' << result << '\n';
		// 배열 재사용할 것이므로 초기화 필수!
		memset(fly, 0, size(fly));
		// result 도 초기화!
		result = 0;
	}
}
