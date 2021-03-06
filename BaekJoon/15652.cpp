#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, cnt;
int arr[9] = { 0, };

void solution(int start, int cnt) {
	// 비내림차순(같은 수 여러번 골라도 됨)
	if (cnt == m) {
		for (int j = 0; j < m; j++) {
			cout << arr[j] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++) {
		arr[cnt] = i;
		solution(i, cnt + 1);
	}
}


void input() {
	cin >> n >> m;
}

int main() {
	input();
	solution(1, 0);
}
