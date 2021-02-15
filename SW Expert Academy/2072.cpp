#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n;
long sum = 0;

bool is_odd(int n) {
	if (n % 2 == 0) return false;

	return true;
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> n;
			if (is_odd(n)) {
				sum += n;
			}
		}
		cout << "#"<< i+1 << ' '<< sum << '\n';
		sum = 0;
	}
}
