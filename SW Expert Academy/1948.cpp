#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int mon1, day1, mon2, day2;
int days[13] = { 0 };
int total[13] = { 0 };
int result;

// 전체 일수 
void solution2() {
	int date1 = total[mon1 - 1] + day1;
	int date2 = total[mon2 - 1] + day2;
	result = date2 - date1 + 1;
}

void solution() {
	result = 0;
	if (mon1 != mon2) {
		for (int i = mon1 + 1; i < mon2; i++) {
			result += days[i];
		}
		result += (days[mon1] - day1 + day2 + 1);
	}
	else
	{
		result += (day2 - day1 + 1);
	}
}

int main() {
	int T;
	cin >> T;

	// day 배열(solution 1)
	for (int i = 1; i < 13; i++) {
		if (i <= 7) {
			if (i == 2)
				days[i] = 28;
			else if (i % 2 == 0)
				days[i] = 30;
			else
				days[i] = 31;
		}
		else {
			if (i % 2 == 0)
				days[i] = 31;
			else
				days[i] = 30;
		}
	}

	// total 배열(solution 2)
	for (int i = 1; i < 13; i++) {
		total[i] = days[i];
	}
	for (int i = 1; i < 13; i++) {
		total[i] += total[i - 1];   // **
	}
	// 확인
	// for (int i = 0; i < 13; i++) {
	// 	printf("%2d\n", days[i]);
	// }
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> mon1 >> day1 >> mon2 >> day2;

		solution2();
		printf("#%d %d\n", test_case, result);
	}

	return 0;
}
