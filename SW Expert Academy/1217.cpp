#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#include <deque>

#define SIZE 10

using namespace std;

int power(int x, int y) {
	if (y == 0) return 1;
	return x * power(x, y - 1);
}

int main() {

	for (int i = 0; i < 10; i++) {
		// 입력
		int test_case;
		int x, y;

		scanf("%d", &test_case);
		scanf("%d %d", &x, &y);


		printf("#%d %d\n", test_case, power(x, y));
	}
	return 0;
}
