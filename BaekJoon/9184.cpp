#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 21

using namespace std;
int cache[MAX][MAX][MAX] = { 0, };

int w(int a, int b, int c) {

	// 기저사례1
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}

	// 기저사례2
	if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20);
	}

	int &result = cache[a][b][c];
	if (result != 0) return result;

	if (a < b && b < c) {
		return result = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	
	return result = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
	int a, b, c;

	while(1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}

	return 0;
}
