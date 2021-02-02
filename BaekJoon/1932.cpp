// 시간 초과 뜸..

#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#define MAX 500

using namespace std;

int n;
int max_val = 0;
int sum = 0;
int arr[MAX][MAX] = { -1, };

// ㅋㅋ다 풀고 보니 이걸 DFS로 볼 수 있는지 의문
int DFS(int i, int j, int sum) {
	if (i > n || j  > n) {
		return sum;
	}

	// 두 갈림길 ** 이렇게 해주면 DFS가 돌아와서 또 다른 DFS로 가니까 안됨!! 둘 중 하나만 가게 했어야 했음!
	/*
		DFS(i + 1, j, sum + arr[i][j]);
		DFS(i + 1, j + 1, sum + arr[i][j]);
	*/
	return max_val = max(DFS(i + 1, j, sum + arr[i][j]), DFS(i + 1, j + 1, sum + arr[i][j]));
}

int main() {
	// 삼각형의 크기 1 <= n <= 500
	cin >> n;

	// 정수 삼각형 입력 받기
	// 트리를 써야 하나?
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> arr[i][j];
		}
	}

	//DFS 이용
	DFS(0, 0, sum);

	
	cout << max_val << '\n';

	return 0;
}
