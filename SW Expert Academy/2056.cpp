#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string date;
		cin >> date;

		// substr: 시작 index, 자르고 싶은 char 개수
		string y = date.substr(0, 4);
		string m = date.substr(4, 2);
		string d = date.substr(6, 2);
		string result = y + "/" + m + "/" + d;
		
		int year = stoi(y);
		int month = stoi(m);
		int day = stoi(d);

		if (month < 1 || month >13) {
			result = "-1";
		}

		// 1월 ~ 7월
		if (month >= 1 && month <= 7) {
			if (month == 2) {
				if (day < 1 || day > 28)
					result = "-1";
			}
			else if (month % 2 == 0) {
				if (day < 1 || day> 30)
					result = "-1";
			}
			else {
				if (day < 1 || day> 31)
					result = "-1";
			}
		}
		// 8월 ~ 12월
		else {
			if (month % 2 == 0) {
				if (day < 1 || day>31)
					result = "-1";
			}
			else {
				if (day < 1 || day>30)
					result = "-1";
			}
		}
		
		printf("#%d ", test_case);
		cout << result << '\n';
	}
	return 0;
}
