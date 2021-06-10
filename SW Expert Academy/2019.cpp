#include <iostream>
#include <algorithm>
#include <string>
#define MAX 30

using namespace std;

int arr[MAX] = { 1, };

// 동적 프로그래밍
int power(int num) {
	if (arr[num] != 0) {
		return arr[num];
	}
	arr[num] = 2 * power(num - 1);
}

int main(int argc, char** argv)
{
	int num;
	cin >> num;

	power(num);
	for (int i = 0; i <= num; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
