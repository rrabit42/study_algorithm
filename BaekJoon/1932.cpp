#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstring> //memset
#include <queue>
#define MAX 500

using namespace std;

int n;
int max_val = 0;
int sum = 0;
int arr[MAX][MAX];
int cache[MAX][MAX];

/*
	int cache[MAX][MAX] = { -1 }; 이든 ,를 붙이든
	ㅋㅋㅋ 이러면 첫번째 원소만 -1이 됨....ㅇㄴ
*/

// DP를 통해 이미 탐색 했던 값을 저장하는 것, Memoization(재활용), 을 해줘야 시간 초과가 나지 않는다.
// 불필요한 연산 줄이기! 즉, 결과를 저장하는 장소를 마련해 두고, 한번 계산한 값을 저장해뒀다 재활용(일종의 캐시)
// 재귀 호출이 깊어지면 깊어질수록, 탐색량이 많아질 수록 빛을 발한다!
int maxSum(int i, int j) {

	// 레퍼런스 변수: 대입된 변수의 값과 주소를 모두 가짐(선언 시 초기화 필수)
	// 레퍼런스 변수(now)가 바뀌면 arr[i][j]도 값이 바뀜
	int &result = cache[i][j];
	
	if (result != -1) {
		return result;
	}

	// 맨 아랫줄
	if (i == n - 1) {
		return result = arr[i][j];
	}

	// 두 갈림길 ** 이렇게 해주면 DFS가 돌아와서 또 다른 DFS로 가니까 안됨!! 둘 중 하나만 가게 했어야 했음!
	/*
		DFS(i + 1, j, sum + arr[i][j]);
		DFS(i + 1, j + 1, sum + arr[i][j]);
	*/
	return result = max(maxSum(i + 1, j), maxSum(i + 1, j + 1)) + arr[i][j];
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

	// -1로 초기화
	memset(cache, -1, sizeof(cache));

	//DFS 이용
	cout << maxSum(0, 0) << '\n';

	return 0;
}


/*
// 시간 초과 뜸..
더 오래 걸리는 이유가
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

여기서 3과 8 양갈래로 나뉘어짐. 2번째의 행 3에서 8까지의 합 최대, 1까지의 합 최대를 찾고, 2번째 행 8쪽에서 1까지의 합 최대, 0까지의 합 최대를 찾음.
근데 1까지의 합 최대 구하는게 겹치는데도 불구하고 얘네들이 서로 따로 구하느라 시간이 오래 걸리는것!!
위의 방법은 이를 대비해 값을 저장해놔서 2번째 행 8쪽에서 1까지의 합 최대를 찾을 때 3이 이미 구해놨던거 쓸 수 있도록 memoization 하는 것!!!!!!~.~

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
	// DFS(i + 1, j, sum + arr[i][j]);
	// DFS(i + 1, j + 1, sum + arr[i][j]);
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
*/
