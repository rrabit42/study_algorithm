#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#define MAX 41

using namespace std;

int t, n;
int arr[MAX][2]; // 0 count, 1 count


// 피보나치 단순하게 빠르게 출력하는건 가능한데,
// 저 count를 어떻게 출력할지가 정말 곤란...
// 아니,, 걍 횟수만 출력하면 되네 이런 미친..ㅋㅋㅋ 

int fibonacci0(int n) {

	int &result = arr[n][0];

	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return 0;
	}
	else if (result != -1) {
		return result;
	}
	
	return result = fibonacci0(n - 1) + fibonacci0(n - 2);
}

int fibonacci1(int n) {

	int &result = arr[n][1];

	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (result != -1) {
		return result;
	}

	return result = fibonacci1(n - 1) + fibonacci1(n - 2);
}

int main() {
	cin >> t;

	memset(arr, -1, sizeof(arr));
	arr[0][0] = 1; arr[0][1] = 0;
	arr[1][0] = 0; arr[1][1] = 1;


	for (int i = 0; i < t; i++) {
		cin >> n;
		fibonacci0(n); fibonacci1(n);
		cout << arr[n][0] << ' ' << arr[n][1] << '\n';
	}
}
