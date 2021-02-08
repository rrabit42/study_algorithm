#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int visited[MAX];
int print[MAX];

// DFS를 통한 조합 구하기
void DFS(int cnt, int start) {
	// 배열 출력
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << print[i] << ' ';
		}
		cout << endl;
		return;
	}

	// 조건에 맞는 출력 배열 만들기
	for (int i = start; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			print[cnt] = i;
			DFS(cnt + 1, i + 1);  // 이렇게 하면 수열 원소가 1개일 때 123 23 3 이렇게 나옴..
								  // ** 와 그냥 i+1을 넘겨주면 되는 거였음... 그 다음 원소는 현재보다 크게 시작하게
			visited[i] = 0;
		}
	}
}

int main() {
	// [1,n] 에서 중복없이 m개 고름
	cin >> n >> m;

	// 수열은 오름차순, 사전 순으로 증가하는 순서
	DFS(0, 1);

	return 0;
}
