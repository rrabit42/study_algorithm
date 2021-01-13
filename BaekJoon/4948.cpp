#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
#define MAX (123456 * 2 + 1) // 배열 범위(수 범위까지)

// 한꺼번에 입력받고 한꺼번에 출력하기
int main() {
	int n, n2, i, j, cnt;
	bool arr[MAX];
	long input[1000];

	// 배열 초기화
	for (i = 0; i < MAX; i++) {
		arr[i] = true;
	}

	// 에라토스테네스의 체
	for (i = 2; i <= sqrt(MAX - 1); i++) {
		if (arr[i]) {
			for (j = i + i; j < MAX; j += i) {
				if (arr[j]) {
					arr[j] = false;
				}
			}
		}
	}

	// 입력 받기
	i = -1;
	do {
		i++;
		cin >> input[i];
	} while (input[i]);

	i = 0;
	while (input[i]) {
		cnt = 0;
		for (j = input[i] + 1; j <= (input[i] * 2); j++) {
			if (arr[j]) {
				cnt += 1;
			}
		}
		cout << cnt << endl;
		i++;
	}
	
	return 0;
}

// 한꺼번에 안하고 각 test case에 대해 출력만 나오면 되는군..!
/*
int main() {
	// 에라토스테네스의 체 사용
	// 입력 범위(index)에서 소수를 거른 배열을 사용
	int n, n2, i, j, cnt;
	bool arr[246913];

	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		cnt = 0; // 소수 개수 count
		n2 = n * 2;

		// 먼저 true로 초기화
		for (i = 2; i <= n2; i++) arr[i] = true;

		// 소수 판별 (소수이면 true, 소수가 아니면 false)
		for (i = 2; i <= sqrt(n2); i++) {
			if (arr[i]) {
				// 소수의 배수들 다 false로 바꾸기
				for (j = i + i; j <= n2; j += i) {
					if (arr[j]) {
						arr[j] = false;
					}
				}
			}
		}

		// 범위 내 소수 개수 구하기
		for (i = n + 1; i <= n2; i++) {
			if (arr[i]) cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}
*/

// 시간 초과 나옴
/*
#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 10000

bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}

	for (int k = 2; k <= sqrt(n); k++) {
		if ((n % k) == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	// long 쓰는걸 습관화하자
	long arr[MAX] = {0,};
	int i = -1, j;
	long start, end, sum;
	do {
		i++;
		cin >> arr[i];
	} while (arr[i]);
	
	i = 0;
	while (arr[i]) {
		sum = 0;

		start = arr[i] + 1;
		end = arr[i] * 2;

		for (j = start; j <= end; j++) {
			if (isPrime(j)) {
				sum += 1;
			}
		}
		cout << sum << endl;
		i++;
	}

	return 0;
}
*/
