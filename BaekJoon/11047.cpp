#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int n, k, i, sum = 0;
	int arr[10];
	cin >> n >> k;

	// 계산하기 쉽게 낮은 index에 높은 가치값 받음
	for (i = 0; i < n; i++) {
		cin >> arr[n - 1 - i];
	}

	int temp = k;
	int q;
	for (i = 0; temp > 0; i++) {
		if (arr[i] > k) // 가치값이 k보다 크면 당연히 pass 해야지
			continue;
		q = (int)(temp / arr[i]);  // 몫 구하기
		sum += q;
		temp -= arr[i] * q;
	}

	cout << sum << endl;
}
