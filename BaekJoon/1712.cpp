#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>
#define MAX 100000

using namespace std;

/*
	고정비용: A
	가변비용: B
	판매가격(판매비용, 총 수입): C
	총 비용: A+B
	생산 대수: N

	즉, CN - (A+BN) >0 일 때 최소 N 구하기
	정리하면 (C-B)N > A
*/

int main() {
	long a, b, c, i;
	cin >> a >> b >> c;

	long profit = c - b;

	if (profit <= 0) {
		cout << -1 << '\n';
		return 0;
	}
	/*
	시간 초과 뜬다!
	else {
		for (i = 1; i < MAX; i++) {
			if (profit*i > a) {
				break;
			}
		}
		
	}
	cout << i << '\n';
	return 0;
	*/
	cout << a / profit + 1 << '\n'; // +1 해주는 이유는 몫이 나오는데 딱 나누어떨어지면 1개 더 팔아야 초과! 가 되고, 반올림도 할 수 있게!
	return 0;
}
