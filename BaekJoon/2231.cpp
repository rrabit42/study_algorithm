#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
	// 1,000,000 이기 때문에 long 사용해야함
	long n, m, remain, temp, sum;

	cin >> n;
	string n_str = to_string(n);
	int len = n_str.length();

	// 각 자릿수 합은 커봤자 6 * 9 = 54라는 것을 이용.
	// 그럼 m의 범위는 n-54 <= m <= n 일 수 밖에! ㅠㅠ
	// 분해합은 최소 n - 9*(자릿수) 부터 시작
	long begin = n - len * 9;

	for (long i = begin; i <= n; i++) {
		sum = i;
		temp = i;
		// m의 자리수 합산
		while (temp) {
			sum += temp % 10;
			temp /= 10;
		}
		
		if (n == sum) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "0" << endl;
	return 0;

	/*
		// 첫 풀이

		int n, m, remain, sum = 0;

		cin >> n;
		string n_str = to_string(n);
		int len = n_str.length();

		// 분해합의 마지막 3자리만 영향을 받음
		m = (int)(n / 1000);

		// 나머지를 계산해보자.
		remain = (int)(n % 1000);

		// m의 자리수 합산(마지막 3자리 제외)
		for (int i = 0; i < len - 3; i++) {
			sum += (int)(n_str[i]);
		}

		// n = (m + 100*a + 10*b + c) + sum + a + b + c 이므로
		// remain = 100*a + 10*b + c + sum + a + b + c
		// remain - sum = 101 * a + 11 * b + 2c
		int goal = remain - sum;
		for (int a = 0; a < 10; a++) {
			for (int b = 0; b < 10; b++) {
				for (int c = 0; c < 10; c++) {
					if (goal == 101 * a + 11 * b + 2 * c) {
						// 아 미친;; 그냥 return이 아니라 프린트를 해야지!!!!
						return m + 100 * a + 10 * b + c;
					}
				}
			}
		}
		// 여기도 마찬가지..
		return 0;
	*/
}
