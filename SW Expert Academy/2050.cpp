#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int T;
string str;

void input() {
	cin >> str;
}

void solution() {
	for (int test = 0; test < T; test++) {
		input();
		int offset = 'A' - 1;
		printf("%d\n", 'A');
		for (int i = 0; i < str.length(); i++) {
			printf("%d ", str[i] - offset);
		}
	}
}
int main() {
	cin >> T;
	solution();
	return 0;
}
