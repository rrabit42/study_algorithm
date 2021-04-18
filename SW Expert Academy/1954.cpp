#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#include <deque>

#define SIZE 10

using namespace std;

int T;
int n;
int arr[SIZE][SIZE];

void solution() {
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n;
		int N = n;
		
		// 변수 2개로 하는 법!
		int row = 0, col = -1;
		int dir = 1; // direction
		int num = 1;

		// 사실 이 초기화는 없어도 될듯
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				arr[i][j] = 0;
			}
		}

		while (n > 0) {

			// 열 증감
			for (int i = 0; i < n; i++) {
				col += dir;	// 먼저 해주기(반복을 고려할 때, 그 다음 칸부터 시작해야해서)
				arr[row][col] = num;
				
				num++;
			}

			n--; // 채워야하는 줄 수 줄이기 **

			// 행 증감
			for (int j = 0; j < n; j++) {
				row += dir;
				arr[row][col] = num;

				num++;
			}

			dir *= -1;
		}

		// 결과 출력
		printf("#%d\n", test_case);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}
}
int main() {
	cin >> T;

	solution();

	return 0;
}


// 밑은 내가 푼거(학교에서 배운거)

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#include <deque>

#define SIZE 10

using namespace std;

int T;
int n;
int arr[SIZE][SIZE];

void solution() {
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n;
		
		// 초기화
		int left = 0, right = n - 1;
		int top = 0, bottom = n - 1;
		int num = 1;

		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				arr[i][j] = 0;
			}
		}


		while (left <= right && top <= bottom) {

			// for 쓰는 거..
			for (int j = left; j <= right; j++, num++) {
				arr[top][j] = num;
				//num++;	// ++를 어디다가 할지
			}
			top++;	// + 되는 부분...

			for (int i = top; i <= bottom; i++, num++) {
				arr[i][right] = num;
			}
			right--;

			for (int j = right; j >= left; j--, num++) {
				arr[bottom][j] = num;
			}
			bottom--;

			for (int i = bottom; i >= top; i--, num++) {
				arr[i][left] = num;
			}
			left++;
			
		}

		// 결과 출력
		printf("#%d\n", test_case);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}
}
int main() {
	cin >> T;

	solution();

	return 0;
}
