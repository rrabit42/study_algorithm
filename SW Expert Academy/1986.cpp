#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int T;
int num;
int result[11] = { 0 };

void input() {
	cin >> num;
}

void solution() {

	for (int i = 1; i <= 10; i++) {
		if (i % 2 == 0) {
			result[i] = result[i - 1] - i;
		}
		else {
			result[i] = result[i - 1] + i;
		}
	}

	for (int test_case = 1; test_case <= T; test_case++) {
		input();
		
		printf("#%d %d\n", test_case, result[num] );
	}
}
int main() {
	cin >> T;

	solution();
	return 0;
}
